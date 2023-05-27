#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

typedef struct s_client
{
	int id;
	char id_str[25];
	int sock;
	struct sockaddr_in addr;
	socklen_t addr_len;
	char *buf;
	struct s_client *next;
} t_client;

typedef struct s_server
{
	int sock;
	struct sockaddr_in addr;
	t_client *client_list;
	int id_next_client;
	fd_set save_set, read_set, write_set;
} t_server;

void fatal()
{
	char *str = "Fatal error\n";
	write(2, str, strlen(str));
	exit(1);
}

void setup_server(t_server *s, int port)
{
	s->client_list = NULL;
	s->id_next_client = 0;
	FD_ZERO(&s->save_set);

	// socket create and verification
	s->sock = socket(AF_INET, SOCK_STREAM, 0);
	if (s->sock == -1)
		fatal();

	// assign IP, PORT
	bzero(&s->addr, sizeof(struct sockaddr_in));
	s->addr.sin_family = AF_INET;
	s->addr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	s->addr.sin_port = htons(port);

	// Binding newly created socket to given IP and verification
	if (0 != bind(s->sock, (const struct sockaddr *)&s->addr, sizeof(struct sockaddr_in)))
		fatal();

	// Listening
	if (0 != listen(s->sock, SOMAXCONN))
		fatal();

	FD_SET(s->sock, &s->save_set);
}

void add_client(t_server *server)
{
	// creating the client
	t_client *c = calloc(1, sizeof(t_client));
	if (c == NULL)
		fatal();
	c->addr_len = sizeof(struct sockaddr_in);
	c->sock = accept(server->sock, (struct sockaddr *)&c->addr, &c->addr_len);
	if (c->sock < 0)
	{
		write(2, "error with accept()\n", 20);
		free(c);
		return;
	}
	FD_SET(c->sock, &server->save_set);
	c->id = server->id_next_client;
	sprintf(c->id_str, "client %d: ", c->id);
	server->id_next_client = server->id_next_client + 1;

	// adding the client to client list (add front)
	c->next = server->client_list;
	server->client_list = c;

	// announcing the new client
	char welcome_msg[50];
	sprintf(welcome_msg, "server: client %d just arrived\n", c->id);
	t_client *browse = c->next;
	while (browse)
	{
		if (FD_ISSET(browse->sock, &server->write_set)) // This cannot evaluate as true for the new client, as it has not gotten a chance to go through select() yet
			send(browse->sock, welcome_msg, strlen(welcome_msg), 0);
		browse = browse->next;
	}
}

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

int extract_message_rest(char **buf, char **msg)
{
	char *newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n' || (*buf)[i + 1] == '\0')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char *newbuf;
	int len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void dispatch_msg(t_client **client, t_server *server, int *skip_increment)
{
	char read_buf[10];
	int recv_return = recv((*client)->sock, read_buf, 9, 0);
	if (recv_return > 0)
	{
		read_buf[recv_return] = 0;
		(*client)->buf = str_join((*client)->buf, read_buf);
		char *msg = NULL;
		char *to_send = NULL;
		while (extract_message(&(*client)->buf, &msg))
		{
			to_send = str_join(to_send, (*client)->id_str);
			to_send = str_join(to_send, msg);
			free(msg);
		}
		t_client *browse = server->client_list;
		while (browse && to_send)
		{
			if (browse->id != (*client)->id && FD_ISSET(browse->sock, &server->write_set))
				send(browse->sock, to_send, strlen(to_send), 0);
			browse = browse->next;
		}
		free(to_send);
	}
	else
	{
		char *msg = NULL;
		char *to_send = NULL;
		while (extract_message_rest(&(*client)->buf, &msg))
		{
			to_send = str_join(to_send, (*client)->id_str);
			to_send = str_join(to_send, msg);
			free(msg);
		}
		t_client *browse2 = server->client_list;
		while (browse2 && to_send)
		{
			if (browse2->id != (*client)->id && FD_ISSET(browse2->sock, &server->write_set))
				send(browse2->sock, to_send, strlen(to_send), 0);
			browse2 = browse2->next;
		}
		free(to_send);

		t_client *to_delete = (*client);
		*client = to_delete->next;
		*skip_increment = 1;

		char goodbye_msg[50];
		sprintf(goodbye_msg, "server: client %d just left\n", to_delete->id);
		free(to_delete->buf);
		FD_CLR(to_delete->sock, &server->save_set);
		close(to_delete->sock);

		// reconnecting the list around the deleted node
		if (to_delete == server->client_list) 
			server->client_list = to_delete->next;
		else
		{
			t_client *parent_of_to_delete = server->client_list;
			while (parent_of_to_delete && parent_of_to_delete->next != to_delete)
				parent_of_to_delete = parent_of_to_delete->next;
			parent_of_to_delete->next = to_delete->next;
		}

		t_client *browse = server->client_list;
		while (browse)
		{
			if (FD_ISSET(browse->sock, &server->write_set))
				send(browse->sock, goodbye_msg, strlen(goodbye_msg), 0);
			browse = browse->next;
		}
		free(to_delete);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		char *str = "Wrong number of arguments\n";
		write(2, str, strlen(str));
		exit(1);
	}

	t_server server;
	setup_server(&server, atoi(argv[1]));

	while (1)
	{
		server.read_set = server.save_set;
		server.write_set = server.save_set;

		if (-1 == select(FD_SETSIZE, &server.read_set, &server.write_set, NULL, NULL))
			continue;
		if (FD_ISSET(server.sock, &server.read_set))
			add_client(&server);
		t_client *browse = server.client_list;
		while (browse)
		{
			int skip_increment = 0;
			if (FD_ISSET(browse->sock, &server.read_set))
				dispatch_msg(&browse, &server, &skip_increment);
			if (skip_increment == 0) // if we delete the node in the list, we have to increment the pointer in dispatch_msg and skip here
				browse = browse->next;
		}
	}
	return 0;
}