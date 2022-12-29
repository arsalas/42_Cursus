# COLORS
GREEN			:= \033[32m
YELLOW			:= \033[33m
BLUE			:= \033[34m
NC				:= \033[m

# FLAGS
CC				:= c++
FLAGS 			:= -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

RM 				:= rm -f

# SRC
SRCS 			=  main.cpp Base.cpp A.cpp B.cpp C.cpp
					
# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin


# OBJECTS
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

#INCLUDES
INCLUDES 		:= src

INC			= $(addprefix -I , $(INCLUDES))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 				:= ex02

# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.cpp src

.SECONDEXPANSION:

all:$(BIN)

$(OBJS_DIR)/%.o: %.cpp | $$(@D)
	@printf "\r$(BLUE)Generating $(NAME) objects... %-38.38s$(NC)" $@
	@$(CC) $(FLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 
	@printf "\r%-38.38s$(NC)"


$(BIN): $(OBJS) $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC) $(OBJS) -o $(BIN)
	printf '\033[1A\033[K'
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

run: $(BIN)
	@./$(BIN)


leaks: $(BIN)
	@which valgrind | grep -o valgrind > /dev/null && \
	valgrind --leak-check=yes ./$(BIN) || \
	leaks -atExit -- ./$(BIN)

clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean:		clean
	@$(RM) $(BIN)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)

.PHONY: all clean fclean re leaks run
