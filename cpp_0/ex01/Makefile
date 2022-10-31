CFLAGS 	= -Wall -Wextra -Werror
CC		= g++

SRCS 	= main.cpp PhoneBook.cpp Contact.cpp

OBJS_DIR	= obj

BIN_DIR	= bin

OBJS		= $(addprefix  $(OBJS_DIR)/, $(SRCS:.cpp=.o))

INC = colors.hpp PhoneBook.hpp Contact.hpp

NAME	= PhoneBook

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

.PHONY:		all clean fclean re