CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= main.c \
		./src/functions/maps.c \
		./src/gnl/get_next_line.c \
		./src/gnl/get_next_line_utils.c \

OBJS 	= ${SRCS:.c=.o}

NAME 	= so_long.a

RM 		= rm -f

.c.o:	
	make -C libft
	make -C mlx
	gcc -c ${CFLAGS} -Imlx $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			gcc ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a mlx/libmlx.a ${NAME} -o so_long

clean:
			${RM} ${OBJS}
			make clean -C libft
			make clean -C mlx

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft
			make fclean -C mlx

re:			fclean all

.PHONY:		all clean fclean re