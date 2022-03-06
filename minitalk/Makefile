CFLAGS 	= -Wall -Wextra -Werror

SRCS_C 	= client.c

SRCS_S 	= server.c

OBJS_C 	= ${SRCS_C:.c=.o}

OBJS_S 	= ${SRCS_S:.c=.o}

NAME	= minitalk

NAME_C 	= client.a

NAME_S 	= server.a

RM 		= rm -f

.c.o:	
	make -C libft
	make -C printf
	gcc -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS_C} ${OBJS_S}
			ar rc ${NAME_C} ${OBJS_C}
			ar rc ${NAME_S} ${OBJS_S}
			gcc ${CFLAGS} ${NAME_C} libft/libft.a ./printf/libftprintf.a -o client
			gcc ${CFLAGS} ${NAME_S} libft/libft.a ./printf/libftprintf.a -o server

clean:
			${RM} ${OBJS_C}
			${RM} ${OBJS_S}
			make clean -C libft

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re