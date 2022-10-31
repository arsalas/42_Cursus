CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

B_SRCS 	= ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJS 	= ${SRCS:.c=.o}

B_OBJS 	= ${B_SRCS:.c=.o}

NAME 	= libft.a

RM 		= rm -f

.c.o:	
	@gcc -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} libft.h
	@ar rc ${NAME} ${OBJS}
	@echo "\x1b[32mlibf compiled!"

bonus:		${B_OBJS} ${OBJS}
	ar rc ${NAME} ${OBJS} ${B_OBJS}

clean:
	@${RM} ${OBJS} ${B_OBJS}
	@echo "\x1b[32mlibft cleaned!"

fclean:		clean
	@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re