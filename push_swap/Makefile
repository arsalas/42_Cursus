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
SRCS_M 			= actions_1.c actions_2.c actions_3.c \
				errors.c \
				helpers.c \
				maths.c \
				parse.c \
				sorting_1.c sorting_2.c sorting_3.c \
				stack.c stack_aux.c

SRCS			= main.c $(SRCS_M)

SRCS_B 			= main_bonus.c \
				checker_bonus.c \
				actions_1.c actions_2.c actions_3.c \
				errors.c \
				helpers.c \
				parse.c \
				stack.c stack_aux.c \
				get_next_line_bonus.c get_next_line_utils_bonus.c \
				


# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin


# OBJECTS
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_B		= $(addprefix $(OBJS_DIR)/, $(SRCS_B:.c=.o))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPS_B				= $(patsubst %.o, %.d, $(OBJS_B)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 				:= push_swap
NAME_B				:= checker

# LIBS
LIBS_PATH			:= libs
LIBFT_PATH			:= libft
LIBFT				:= $(LIBS_PATH)/$(LIBFT_PATH)/bin/libft.a
LIBS 				:= $(LIBFT)

#INCLUDES
INCLUDES 		:= $(LIBS_PATH)/$(LIBFT_PATH) includes
INC				= $(addprefix -I, $(INCLUDES))


# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)
BIN_B = $(BIN_DIR)/$(NAME_B)

vpath %.c src src/actions src/errors src/helpers src/maths src/parse src/sorting src/stacks src/checker src/gnl
vpath %.h includes
.SECONDEXPANSION:

all: $(LIBFT) $(BIN)

bonus:  $(LIBFT) $(BIN_B)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@echo "🔃 $(YELLOW)Compiling" $(basename $(notdir $@)) "$(NC)"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 

$(LIBFT): libft_force_make
	@make -C $(LIBS_PATH)/$(LIBFT_PATH)

$(BIN): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC) $(OBJS) $(LIBS) -o $(BIN)
	@echo "✅ $(GREEN)$(NAME) compiled!$(NC)"

$(BIN_B): $(OBJS_B)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(FLAGS) $(INC_B) $(OBJS_B) $(LIBS) -o $(BIN_B)
	@echo "✅ $(GREEN)$(NAME_B) compiled!$(NC)"

run: $(BIN)
	@./$(BIN)

leaks: $(BIN)
	@which valgrind | grep -o valgrind > /dev/null && \
	valgrind --leak-check=yes ./$(BIN) || \
	leaks -atExit -- ./$(BIN)

norm:
	@norminette src

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
	@$(RM) $(BIN_B)
	@$(RM) -rf  $(BIN_DIR)
	@make file_clean -C $(LIBS_PATH)/$(LIBFT_PATH)

re:	fclean all

re_bonus: fclean bonus

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)
-include $(DEPS_B)

.PHONY: all clean fclean re re_bonus leaks run libft_force_make 
