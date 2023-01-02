# COLORS
RED				:= \033[31m
GREEN			:= \033[32m
YELLOW			:= \033[33m
BLUE			:= \033[34m
NC				:= \033[m



CXX				:= c++
DEBUG_MSG		:= true

# FLAGS
W_FLAGS			:= -Wall -Wextra -Werror
VERSION			:= -std=c++98 
SANITIZER		:= -g -fsanitize=address
FDEBUG			:=  -D DEBUG=$(DEBUG_MSG)
FLAGS			:= $(W_FLAGS) $(VERSION) $(SANITIZER) $(FDEBUG)

RM 				:= rm -f

# SRC
SRCS 			=  main.cpp

# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin


# OBJECTS
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

#INCLUDES
INCLUDES 		:= src/

INC			= $(addprefix -I , $(INCLUDES))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 				:= ft_containers

# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.cpp src

.SECONDEXPANSION:

all:$(BIN)

$(OBJS_DIR)/%.o: %.cpp | $$(@D)
	@echo "🔃 $(YELLOW)Compiling" $(basename $(notdir $@)) 
	@$(CXX) $(FLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 

$(BIN): $(OBJS) $(BIN_DIR)
	@$(CXX) $(FLAGS) $(INC) $(OBJS) -o $(BIN)
	@echo "✅ $(GREEN)$(NAME) compiled!$(NC)"

run: $(BIN)
	@./$(BIN)


leaks: $(BIN)
	@which valgrind | grep -o valgrind > /dev/null && \
	valgrind --leak-check=yes ./$(BIN) || \
	leaks -atExit -- ./$(BIN)

clean:
	@echo "🧹 $(RED)$(NAME) removing...$(NC)"
	@$(RM) $(OBJS) $(DEPS)
	@echo "✅ $(GREEN)$(NAME) cleaned!$(NC)"
	@$(RM) -rf  $(OBJS_DIR)

fclean:		clean
	@$(RM) $(BIN)
	@$(RM) -rf  $(BIN_DIR)

re:	fclean all

re_bonus: fclean bonus


$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)

.PHONY: all clean fclean re leaks run re_bonus
