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
				actions_aux.c \
				maths.c \
				parse.c \
				sorting.c \
				stack.c 


# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin


# OBJECTS
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 				:= push_swap

# LIBS
LIBS_PATH			:= libs
LIBFT_PATH			:= libft
LIBFT				:= $(LIBS_PATH)/$(LIBFT_PATH)/bin/libft.a
LIBS 				:= $(LIBFT)

#INCLUDES
INCLUDES 		:= $(LIBS_PATH)/$(LIBFT_PATH)/ includes/ \
				src/mandatory/actions src/mandatory/errors \
				src/mandatory/helpers src/mandatory/parse \
				src/mandatory/stacks src/mandatory/maths src/mandatory/sorting

INC			= $(addprefix -I , $(INCLUDES))
# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.c src/mandatory  src/mandatory/actions src/mandatory/errors src/mandatory/helpers src/mandatory/parse src/mandatory/stacks src/mandatory/maths src/mandatory/sorting

.SECONDEXPANSION:

all: $(LIBFT) $(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@echo "🔃 $(YELLOW)Compiling" $(basename $(notdir $@)) 
	@$(CC) $(FLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 

$(LIBFT): libft_force_make
	@make -C $(LIBS_PATH)/$(LIBFT_PATH)

$(BIN): $(OBJS) $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC) $(OBJS) $(LIBS) -o $(BIN)
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
	@make clean -C $(LIBS_PATH)/$(LIBFT_PATH)

fclean:		clean
	@$(RM) $(BIN)
	@$(RM) -rf  $(BIN_DIR)
	@make file_clean -C $(LIBS_PATH)/$(LIBFT_PATH)

re:	fclean all

re_bonus: fclean bonus

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)

.PHONY: all clean fclean re leaks run libft_force_make 
