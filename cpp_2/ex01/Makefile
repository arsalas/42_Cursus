CFLAGS 	= -Wall -Wextra -Werror
CC		= g++

SRCS 	= main.cpp Fixed.cpp
HEADERS 	= Fixed.hpp

OBJS_DIR	= obj

OBJS		= $(addprefix  $(OBJS_DIR)/, $(SRCS:.cpp=.o))

NAME	= ex00
RM 		= rm -f

all:	$(NAME)

.SECONDEXPANSION:

$(OBJS_DIR)/%.o: %.cpp | $$(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\x1b[32mex01 compiled!\x1b[0m"

clean:
	@$(RM) $(OBJS)
	@echo "\x1b[32mcleaned!\x1b[0m"

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

.PHONY:		all clean fclean re