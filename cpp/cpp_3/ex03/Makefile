CFLAGS 	= -Wall -Wextra -Werror
CC		= g++

SRCS 	= main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
HEADERS 	= ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp

OBJS_DIR	= obj
BIN_DIR	= bin

OBJS		= $(addprefix  $(OBJS_DIR)/, $(SRCS:.cpp=.o))

NAME	= ex03
RM 		= rm -f

all:	$(NAME)

.SECONDEXPANSION:

$(OBJS_DIR)/%.o: %.cpp | $$(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS) $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(BIN_DIR)/$(NAME)
	@echo "\x1b[32mex01 compiled!\x1b[0m"

run: $(NAME)
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