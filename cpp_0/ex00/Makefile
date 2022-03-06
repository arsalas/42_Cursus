CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= megaphone.cpp

OBJS	= ${SRCS:.c=.o}

NAME	= contacts.a

NAME_EX	= contacts

RM 		= rm -f

.c.o:	
	g++ -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			g++ ${CFLAGS} ${SRCS} -o ${NAME_EX}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re