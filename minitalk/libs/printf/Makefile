CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= ft_printf.c \
		ft_printf_utils.c \

OBJS 	= ${SRCS:.c=.o}

NAME 	= libftprintf.a

RM 		= rm -f

.c.o:	
	@gcc -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ft_printf.h
	@ar rc ${NAME} ${OBJS}
	@echo "\x1b[32mprintf compiled!"

clean:
	@${RM} ${OBJS}
	@echo "\x1b[32mprintf cleaned!"


fclean:		clean
	@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re