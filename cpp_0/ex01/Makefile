CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= megaphone.cpp

OBJS	= ${SRCS:.c=.o}

NAME	= megaphone

RM 		= rm -f

.c.o:	
	g++ -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			g++ ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re