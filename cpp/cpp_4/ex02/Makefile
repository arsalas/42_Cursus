CFLAGS 	= -Wall -Wextra -Werror
CC		= g++

SRCS 	= main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
HEADERS 	= Animal.hpp Cat.hpp Dog.hpp Brain.hpp

OBJS_DIR	= obj
BIN_DIR	= bin

OBJS		= $(addprefix  $(OBJS_DIR)/, $(SRCS:.cpp=.o))

NAME	= ex00
RM 		= rm -f

all:	$(BIN_DIR)/$(NAME)

.SECONDEXPANSION:

$(OBJS_DIR)/%.o: %.cpp | $$(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/$(NAME): $(OBJS) $(HEADERS) $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(BIN_DIR)/$(NAME)
	@echo "\x1b[32mex01 compiled!\x1b[0m"

run: $(BIN_DIR)/$(NAME)
	@./$(BIN_DIR)/$(NAME)

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

.PHONY:		all clean fclean re run