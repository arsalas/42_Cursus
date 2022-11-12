CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= so_long.c \
		./src/functions/events.c \
		./src/functions/images.c \
		./src/functions/utils.c \
		./src/functions/maps.c \
		./src/functions/maps2.c \
		./src/gnl/get_next_line.c \
		./src/gnl/get_next_line_utils.c \
		
SRCS_B 	= so_long_bonus.c \
		./src/bonus/events.c \
		./src/bonus/images.c \
		./src/bonus/images_char_1.c \
		./src/bonus/images_char_2.c \
		./src/bonus/utils.c \
		./src/bonus/maps_1.c \
		./src/bonus/maps_2.c \
		./src/bonus/maps_3.c \
		./src/bonus/move.c \
		./src/gnl/get_next_line.c \
		./src/gnl/get_next_line_utils.c \

OBJS 	= ${SRCS:.c=.o}

OBJS_B 	= ${SRCS_B:.c=.o}

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

bonus:		${OBJS_B}
			ar rc ${NAME} ${OBJS_B}
			gcc ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a mlx/libmlx.a ${NAME} -o so_long

run:
	./so_long map.ber

clean:
			${RM} ${OBJS} ${OBJS_B}
			make clean -C libft
			make clean -C mlx

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft
			make clean -C mlx

re:			fclean all

.PHONY:		all clean fclean re bonus
