CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= main.c \
		actions_1.c \
		actions_2.c \
		actions_3.c \
		actions_aux_1.c \
		actions_aux_2.c \

OBJS 	= ${SRCS:.c=.o}

NAME 	= push_swap.a

RM 		= rm -f

.c.o:	
	make -C libft
	gcc -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			gcc ${CFLAGS} ${NAME} ./libft/libft.a -o push_swap

clean:
			${RM} ${OBJS}
			make clean -C libft

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re