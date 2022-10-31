#include <unistd.h>
#include <stdio.h>

int is_pize(char p)
{
	if (p == 'P' || p == 'B' || p == 'R' || p == 'Q' || p == 'K')
		return (1);
	return (0);
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void ft_print(char *str)
{
	write(1, str, ft_strlen(str));
}

typedef struct
{
	char **array;
	int len;
} Board;

typedef struct
{
	int y;
	int x;
} Position;

void create_board(Board *board, char **args, int len)
{
	board->array = args;
	board->len = len;
}

void complete_board(Board *board)
{
	int j;
	for (int i = 0; i < board->len; i++)
	{
		j = 0;
		while (board->array[i][j])
		{
			if (is_pize(board->array[i][j]) == 0)
				board->array[i][j] = '.';
			j++;
		}
	}
}

Position find_king(Board *board)
{
	Position pos;
	int j;

	for (int i = 0; i < board->len; i++)
	{
		j = 0;
		while (board->array[i][j])
		{
			if (board->array[i][j] == 'K')
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
			j++;
		}
	}
	return (pos);
}

int lineal_chess(Board *board, Position k_pos)
{
	int i = 0;
	// Busqueda horizontal
	while (board->array[k_pos.x][i])
	{
		if (board->array[k_pos.x][i] == 'R' || board->array[k_pos.x][i] == 'Q')
			return (1);
		i++;
	}
	// Busqueda vertical
	i = 0;
	while (i < board->len)
	{
		if (board->array[i][k_pos.y] == 'R' || board->array[i][k_pos.y] == 'Q')
			return (1);
		i++;
	}
	return (0);
}

int diagonal_chess(Board *board, Position k_pos)
{
	Position start1 = k_pos;
	Position start2 = k_pos;

	while (start1.x > 0 || start1.y > 0)
	{
		start1.x--;
		start1.y--;
	}
	while (start2.x > 0 || start2.y > 0)
	{
		start2.x++;
		start2.y++;
	}
	// Busqueda 1
	while (start1.x < board->len || start1.y < board->len)
	{
		if (board->array[start1.x][start1.y] == 'Q' || board->array[start1.x][start1.y] == 'B')
			return (1);
		if (board->array[start1.x][start1.y] == 'P' && (k_pos.y == start1.y + 1 && (k_pos.x == start1.x + 1 || k_pos.x == start1.x - 1)))
			return (1);
		start1.x++;
		start1.y++;
	}
	// Busqueda 2
	while (start2.x > 0 || start2.y > 0)
	{
		if (board->array[start2.x][start2.y] == 'Q' || board->array[start2.x][start2.y] == 'B')
			return (1);
		if (board->array[start2.x][start2.y] == 'P' && (k_pos.y == start2.y + 1 && (k_pos.x == start2.x + 1 || k_pos.x == start2.x - 1)))
			return (1);
		start1.x--;
		start1.y--;
	}
	return (0);
}

int is_chess(Board *board)
{
	Position k_pos = find_king(board);
	if (lineal_chess(board, k_pos) == 1)
		return (1);
	else if (diagonal_chess(board, k_pos) == 1)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	Board board;

	if (argc > 1)
	{
		create_board(&board, &argv[1], argc - 1);
		complete_board(&board);
		if (is_chess(&board) == 1)
			ft_print("Success");
		else
			ft_print("Fail");
	}
	ft_print("\n");
	return (0);
}