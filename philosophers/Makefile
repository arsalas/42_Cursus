CFLAGS 	:= -Wall -Wextra -Werror -pthread -g
CC		:= gcc

SRCS 	= main.c \
		thread.c \
		init.c \
		args.c \
		utils.c \
		die.c \
		eat.c \
		forks.c \
		sleep.c

SRCS_B 	= main_bonus.c \
		process_bonus.c \
		args_bonus.c \
		init_bonus.c \
		utils_bonus.c \
		die_bonus.c \
		eat_bonus.c \
		fork_bonus.c \
		sleep_bonus.c \

HEADERS 	= includes/colors.h
HEADERS_M 	= philo/includes/philo.h
HEADERS_B 	= philo_bonus/includes/philo_bonus.h

OBJS_DIR	:= obj

INCLUDES 	:=  includes/ philo/includes/
INC 		= $(addprefix -I , $(INCLUDES))

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_B		= $(addprefix $(OBJS_DIR)/, $(SRCS_B:.c=.o))
OBJS_M		= $(addprefix $(OBJS_DIR)/, $(SRCS_M:.c=.o))

NAME 	:= philo

NAME_B 	:= philo_bonus

RM 		:= rm -f

vpath %.c philo philo/src philo/src/actions philo/src/jobs philo/src/utils  
vpath %.c philo_bonus philo_bonus/src philo/src/actions philo/src/jobs philo_bonus/src/utils  
vpath %.h includes philo/includes philo_bonus/includes 

.SECONDEXPANSION:

all:	$(NAME)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS) $(HEADERS_M)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) -o ./philo/$(NAME)
	@echo "\x1b[32m$(NAME) compiled!\x1b[0m"

bonus:	$(NAME_B)

$(NAME_B): $(OBJS_B) $(HEADERS) $(HEADERS_B)
	@$(CC) $(CFLAGS) $(INC) $(OBJS_B) -o $(NAME_B)
	@echo "\x1b[32m$(NAME_B) compiled!\x1b[0m"

start:
#	@./philo/philo 1 800 200 200
#	@./philo/philo 5 800 200 200
#	@./philo/philo 5 800 200 200 7
#	@./philo/philo 4 410 200 200
	@./philo/philo 4 310 200 100

leaks: $(NAME)
	@leaks -atExit -- ./philo/$(NAME) 2 800 900 900
norminette:
	@norminette | sh ./tests/norminette.sh

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_B)
	@echo "\x1b[32mcleaned!\x1b[0m"

fclean:		clean
	@$(RM) philo/$(NAME)
	@$(RM) philo_bonus/$(NAME_B)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

.PHONY:		all clean fclean re bonus norminette start
