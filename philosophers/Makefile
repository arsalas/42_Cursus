CFLAGS 	= -Wall -Wextra -Werror -pthread

SRCS 	= philo.c \
		src/utils.c \
		src/args.c \

OBJS 	= ${SRCS:.c=.o}

NAME	= philo.a

RM 		= rm -f

.c.o:	
	gcc -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			gcc ${CFLAGS} ${NAME} -o philo

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re