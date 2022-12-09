# COLORS
GREEN			:= \033[32m
BLUE			:= \033[34m
NC				:= \033[m

CFLAGS 	:= -Wall -Wextra -Werror -pthread -g
CC		:= gcc

SRCS 	= main.c \
		thread.c \
		init.c \
		args.c \
		utils.c \
		time.c \
		die.c \
		eat.c \
		forks.c \
		sleep.c

SRCS_B 	= main_bonus.c \
		process_bonus.c \
		threads_bonus.c \
		args_bonus.c \
		init_bonus.c \
		utils_bonus.c \
		time_bonus.c \
		die_bonus.c \
		eat_bonus.c \
		fork_bonus.c \
		sleep_bonus.c \
		exit_bonus.c \
		semaphores_bonus.c \

HEADERS 	= includes/colors.h
HEADERS_M 	= philo/includes/philo.h
HEADERS_B 	= philo_bonus/includes/philo_bonus.h

OBJS_DIR	:= obj
BIN_DIR		:= bin

INCLUDES 	:=  includes/ philo/includes/ philo_bonus/includes/
INC 		= $(addprefix -I , $(INCLUDES))

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_B		= $(addprefix $(OBJS_DIR)/, $(SRCS_B:.c=.o))
OBJS_M		= $(addprefix $(OBJS_DIR)/, $(SRCS_M:.c=.o))

DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPS_B				= $(patsubst %.o, %.d, $(OBJS_B)) 
DEPFLAGS			= -MMD -MF

NAME 	:= philo

NAME_B 	:= philo_bonus

BIN = $(BIN_DIR)/$(NAME)
BIN_B = $(BIN_DIR)/$(NAME_B)

RM 		:= rm -f

vpath %.c philo philo/src philo/src/actions philo/src/jobs philo/src/utils  
vpath %.c philo_bonus philo_bonus/src philo_bonus/src/actions philo_bonus/src/jobs philo_bonus/src/utils  

.SECONDEXPANSION:

all:	$(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 

$(BIN): $(OBJS) $(BIN_DIR)
	@echo "$(BLUE)$(NAME) compiling...$(NC)"
	@$(CC) $(FLAGS) $(MLXFLAGS) $(INC) $(OBJS) $(LIBS) -o $(BIN)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

bonus:	$(BIN_B)

$(BIN_B): $(OBJS_B) $(BIN_DIR)
	@echo "$(BLUE)$(NAME_B) compiling...$(NC)"
	@$(CC) $(FLAGS) $(MLXFLAGS) $(INC) $(OBJS_B) $(LIBS) -o $(BIN_B)
	@echo "$(GREEN)$(NAME_B) compiled!$(NC)"

run: $(BIN)
#	@$(BIN) 1 800 200 200
#	@$(BIN) 5 800 200 200
#	@$(BIN) 5 800 200 200 1
#	@$(BIN) 4 410 200 200
	@$(BIN) 180 420 200 200

run_bonus: $(BIN_B)
#	@$(BIN_B) 1 800 200 200
#	@$(BIN_B) 100 800 200 200
#	@$(BIN_B) 5 800 200 200 1
#	@$(BIN_B) 4 410 200 200
#	@$(BIN_B) 5 420 200 100
	@$(BIN_B) 100 420 200 200

leaks: $(NAME)
	@leaks -atExit -- ./philo/$(NAME) 2 800 900 900

leaks_bonus: $(NAME_B)
	@leaks -atExit -- ./philo_bonus/$(NAME_B) 2 800 900 900
	
norm:
	@echo "\x1b[33mMANDATORY":
	@norminette philo
	@echo "\x1b[33mBONUS":
	@norminette philo_bonus | sh ./tests/norminette.sh

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(RM) $(OBJS_B) $(DEPS_B)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"
	@echo "$(GREEN)$(NAME_B) cleaned!$(NC)"
fclean:		clean
	@$(RM) $(BIN)
	@$(RM) $(BIN_B)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p philo/$(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)


-include $(DEPS)
-include $(DEPS_B)

.PHONY:		all clean fclean re bonus norminette run run_bonus
