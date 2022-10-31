CFLAGS 	= -Wall -Wextra -Werror -g
CC		= gcc

SRCS_C 	= client.c
SRCS_S 	= server.c
SRCS_C_B 	= client_bonus.c
SRCS_S_B 	= server_bonus.c
HEADERS 	= src/minitalk.h
HEADERS_B 	= src/minitalk_bonus.h
LIBS_INCLUDES = libs/libft/libft.a libs/printf/libftprintf.a

OBJS_DIR	= obj

INCLUDES 	= libs/libft/ libs/printf/
INC 		= $(addprefix -I , $(INCLUDES))

OBJS_C 		= $(addprefix  $(OBJS_DIR)/, $(SRCS_C:.c=.o))
OBJS_S 		= $(addprefix  $(OBJS_DIR)/, $(SRCS_S:.c=.o))
OBJS_C_B 	= $(addprefix  $(OBJS_DIR)/, $(SRCS_C_B:.c=.o))
OBJS_S_B 	= $(addprefix  $(OBJS_DIR)/, $(SRCS_S_B:.c=.o))

MANDATORY = .mandatory
BONUS_REQ = .bonus

NAME	= client
NAME_S	= server
RM 		= rm -f

vpath %.c src %.h src

.SECONDEXPANSION:

all:	make_libs $(NAME)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

make_libs:
	@make -C libs/libft
	@make -C libs/printf

$(MANDATORY):
	@touch $(MANDATORY)

$(NAME): $(OBJS_C) $(OBJS_S) $(HEADERS) $(LIBS_INCLUDES) $(MANDATORY)
	@$(CC) $(CFLAGS) $(INC) $(OBJS_C) $(LIBS_INCLUDES) -o $(NAME)
	@$(CC) $(CFLAGS) $(INC) $(OBJS_S) $(LIBS_INCLUDES) -o $(NAME_S)
	@$(RM) $(BONUS_REQ)
	@echo "\x1b[32mminitalk compiled!\x1b[0m"

bonus: make_libs $(BONUS_REQ)

$(BONUS_REQ):  $(OBJS_C_B) $(OBJS_S_B) $(HEADERS_B) $(LIBS_INCLUDES)
	@$(CC) $(CFLAGS) $(INC) $(OBJS_C_B) $(LIBS_INCLUDES) -o $(NAME)
	@$(CC) $(CFLAGS) $(INC) $(OBJS_S_B) $(LIBS_INCLUDES) -o $(NAME_S)
	@$(RM) $(MANDATORY)
	@touch $(BONUS_REQ)
	@echo "\x1b[32mbonus minitalk compiled!\x1b[0m"

norminette:
	@norminette | sh ./tests/norminette.sh

test:
	@sh ./tests/test.sh

test_bonus: $(BONUS_REQ)
	@sh ./tests/test_bonus.sh

test_all:
	@sh ./tests/test_all.sh

leaks_server:
	@leaks -atExit -- ./$(NAME_S)

leaks_client:
	@leaks -atExit -- ./$(NAME)

clean:
	@$(RM) $(OBJS_C)
	@$(RM) $(OBJS_S)
	@$(RM) $(OBJS_C_B)
	@$(RM) $(OBJS_S_B)
	@$(RM) $(MANDATORY)
	@$(RM) $(BONUS_REQ)
	@make -C libs/libft clean
	@make -C libs/printf clean
	@echo "\x1b[32mminitalk cleaned!\x1b[0m"

fclean:		clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_S)

re:			fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

.PHONY:		all clean fclean re norminette leaks_server leaks_client test test_bonus