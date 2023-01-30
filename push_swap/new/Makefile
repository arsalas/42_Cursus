# COLORS
RED				:= \033[31m
GREEN			:= \033[32m
YELLOW			:= \033[33m
BLUE			:= \033[34m
NC				:= \033[m



CC				:= gcc
DEBUG_MSG		:= false

# FLAGS
W_FLAGS			:= -Wall -Wextra -Werror
SANITIZER		:= -g -fsanitize=address
FLAGS			:= $(W_FLAGS) $(SANITIZER)

RM 				:= rm -f

# SRC
SRCS 			=  main.c\
				actions_1.c actions_2.c actions_3.c \
				errors.c \
				actions_aux_1.c actions_aux_2.c digits.c \
				aux_1.c aux_2.c movements.c order.c positions.c stacks.c


# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin


# OBJECTS
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

#INCLUDES
INCLUDES 		:= libs/libft/ includes/

INC			= $(addprefix -I , $(INCLUDES))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 				:= push_swap


LIBS_INCLUDES = libs/libft/libft.a


# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.c src  src/actions src/errors src/helpers src/stacks

.SECONDEXPANSION:

all: $(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@echo "🔃 $(YELLOW)Compiling" $(basename $(notdir $@)) 
	@$(CC) $(FLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 

make_libs:
	@make -C libs/libft

$(BIN): $(OBJS) $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC) $(OBJS) $(LIBS_INCLUDES) -o $(BIN)
	@echo "✅ $(GREEN)$(NAME) compiled!$(NC)"

run: $(BIN)
	@./$(BIN)

leaks: $(BIN)
	@which valgrind | grep -o valgrind > /dev/null && \
	valgrind --leak-check=yes ./$(BIN) || \
	leaks -atExit -- ./$(BIN)

visualizer100:	$(BIN)
	@python3 tests/pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

visualizer500:	$(BIN)
	@python3 tests/pyviz.py `ruby -e "puts (-249..250).to_a.shuffle.join(' ')"`


test: $(BIN) test5 test100 test500

test5:	$(BIN)
	@sh tests/test.sh 1 5 5

test100:	$(BIN)
	@sh tests/test.sh 1 100 5

test500:	$(BIN)
	@sh tests/test.sh 1 500 5


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

.PHONY: all clean fclean re leaks run
