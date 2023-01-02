CFLAGS 	:= -Wall -Wextra -Werror -g
CC		:= gcc

SRCS 	= actions_1.c \
		actions_2.c \
		actions_3.c \
		errors.c \
		actions_aux_1.c \
		actions_aux_2.c \
		digits.c \
		sorting_chunks.c \
		sorting_radial.c \
		sorting_simple.c \
		aux_1.c \
		aux_2.c \
		order.c \
		positions.c \
		stacks.c \

SRCS_M	= main.c

SRCS_B 	= bonus.c main_bonus.c

HEADERS 	= includes/push_swap.h
HEADERS_B 	= includes/push_swap_bonus.h
LIBS_INCLUDES = libft/libft.a

OBJS_DIR	:= obj

INCLUDES 	:=  libft/ includes/
INC 		= $(addprefix -I , $(INCLUDES))

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_B		= $(addprefix $(OBJS_DIR)/, $(SRCS_B:.c=.o))
OBJS_M		= $(addprefix $(OBJS_DIR)/, $(SRCS_M:.c=.o))

NAME 	:= push_swap

NAME_B 	:= checker

RM 		:= rm -f

vpath %.c src src/actions src/errors src/helpers src/sorting src/stacks src/bonus %.h includes

.SECONDEXPANSION:

all:	make_libs $(NAME)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

make_libs:
	@make -C libft

$(NAME): $(OBJS) $(OBJS_M) $(HEADERS) $(LIBS_INCLUDES)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(OBJS_M) $(LIBS_INCLUDES) -o $(NAME)
	@echo "\x1b[32m$(NAME) compiled!\x1b[0m"

bonus:	make_libs $(NAME_B)

$(NAME_B): $(OBJS) $(OBJS_B) $(HEADERS_B) $(LIBS_INCLUDES)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_B) $(LIBS_INCLUDES) -o $(NAME_B)
	@echo "\x1b[32m$(NAME) bonus compiled!\x1b[0m"

test: $(NAME) test5 test100 test500

test5:	$(NAME)
	@sh tests/test.sh 1 5 5

test100:	$(NAME)
	@sh tests/test.sh 1 100 5

test500:	$(NAME)
	@sh tests/test.sh 1 500 5

visualizer100:	$(NAME)
	@python3 tests/pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

visualizer500:	$(NAME)
	@python3 tests/pyviz.py `ruby -e "puts (-249..250).to_a.shuffle.join(' ')"`

leaks: $(NAME)
	@leaks -atExit -- ./$(NAME) 1 2 3 a
#	@valgrind --leak-check=yes ./$(NAME)  1 2 3 a

random10:
	@ruby -e "puts (1..10).to_a.shuffle.join(' ')"

random100:
	@ruby -e "puts (1..100).to_a.shuffle.join(' ')"

random500:
	@ruby -e "puts (1..500).to_a.shuffle.join(' ')"

norminette:
	@norminette | sh ./tests/norminette.sh

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_M)
	@$(RM) $(OBJS_B)
	@$(RM) $(DEPS)
	@$(RM) $(DEPS_M)
	@make clean -C libft
	@echo "\x1b[32mcleaned!\x1b[0m"

fclean:		clean
	@$(RM) $(NAME)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

.PHONY:		all clean fclean re bonus make_libs test test5 test100 test500 visualizer100 visualizer500 leaks random10 random100 random500 norminette