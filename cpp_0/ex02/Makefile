CFLAGS 	= -Wall -Wextra -Werror
CC		= g++

SRCS 	= tests.cpp Account.cpp

OBJS_DIR	= obj

BIN_DIR	= bin

OBJS		= $(addprefix  $(OBJS_DIR)/, $(SRCS:.cpp=.o))

INC = Account.hpp 

NAME	= account

RM 		= rm -f

.SECONDEXPANSION:

all:		$(NAME)

$(OBJS_DIR)/%.o: %.cpp | $$(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(BIN_DIR)/$(NAME)
	@echo "\x1b[32m$(NAME) compiled!\x1b[0m"

run: $(NAME)
	@./$(BIN_DIR)/$(NAME)

test: $(NAME)
	@./$(BIN_DIR)/$(NAME) > result.log
	@diff 19920104_091532.log result.log
clean:
	@$(RM) $(OBJS)
	@echo "\x1b[32mcleaned!\x1b[0m"

fclean:		clean
	@$(RM) $(BIN_DIR)/$(NAME)

re:			fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

.PHONY:		all clean fclean re test run