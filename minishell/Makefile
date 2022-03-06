CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= main.c

OBJS	= ${SRCS_C:.c=.o}

NAME	= minishell.a

EX_NAME	= minishell

RM 		= rm -f

.c.o:	
	gcc -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			gcc ${CFLAGS} ${NAME} -o ${EX_NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re