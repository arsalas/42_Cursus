CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= ft_printf.c \
		ft_printf_utils.c \

OBJS 	= ${SRCS:.c=.o}

NAME 	= libftprintf.a

RM 		= rm -f

.c.o:	
	make -C libft
	gcc -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			make clean -C libft

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re