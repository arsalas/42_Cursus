# COLORS
GREEN			:= \033[32m
YELLOW			:= \033[33m
BLUE			:= \033[34m
NC				:= \033[m

# FLAGS
CC				:= c++
FLAGS 			:= -Wall -Wextra -Werror -std=c++98

RM 				:= rm -f

# SRC
SRCS 			=  main.cpp Harl.cpp

# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin


# OBJECTS
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

#INCLUDES
INCLUDES 		:= 

INC			= $(addprefix -I , $(INCLUDES))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 				:= harlFilter

# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.cpp

.SECONDEXPANSION:

all:$(BIN)

$(OBJS_DIR)/%.o: %.cpp | $$(@D)
	@printf "\r$(BLUE)Generating $(NAME) objects... %-38.38s$(NC)" $@
	@$(CC) $(FLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 


$(BIN): $(OBJS) $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC) $(OBJS) -o $(BIN)
	printf '\033[1A\033[K'
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

run: $(BIN)
	@./$(BIN) INFO


leaks: $(BIN)
	@leaks -atExit -- ./$(BIN) INFO

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
