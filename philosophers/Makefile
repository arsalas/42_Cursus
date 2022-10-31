CFLAGS 	= -Wall -Wextra -Werror -pthread -Iinclude
CC		= gcc
SRC_DIR = src
OBJ_DIR = obj

F_JOB = jobs
F_UTILS = utils
F_ACTIONS = actions
FOLDERS = $(F_JOB) \
		$(F_UTILS) \
		$(F_ACTIONS) \

OBJ_FOLDERS = $(OBJ_DIR)/$(F_JOB) \
			$(OBJ_DIR)/$(F_UTILS) \
			$(OBJ_DIR)/$(F_ACTIONS) \

SRCS 	= $(SRC_DIR)/main.c \
		$(SRC_DIR)/$(F_JOB)/thread.c \
		$(SRC_DIR)/$(F_UTILS)/init.c \
		$(SRC_DIR)/$(F_UTILS)/args.c \
		$(SRC_DIR)/$(F_UTILS)/utils.c \
		$(SRC_DIR)/$(F_ACTIONS)/die.c \
		$(SRC_DIR)/$(F_ACTIONS)/eat.c \
		$(SRC_DIR)/$(F_ACTIONS)/fork.c \
		$(SRC_DIR)/$(F_ACTIONS)/sleep.c \

SRCS_B	= 

OBJS 	= $(OBJ_DIR)/main.o \
		$(OBJ_DIR)/$(F_JOB)/thread.o \
		$(OBJ_DIR)/$(F_UTILS)/init.o \
		$(OBJ_DIR)/$(F_UTILS)/args.o \
		$(OBJ_DIR)/$(F_UTILS)/utils.o \
		$(OBJ_DIR)/$(F_ACTIONS)/die.o \
		$(OBJ_DIR)/$(F_ACTIONS)/eat.o \
		$(OBJ_DIR)/$(F_ACTIONS)/fork.o \
		$(OBJ_DIR)/$(F_ACTIONS)/sleep.o \

SRCS_B	= 

NAME	= philo

NAME_BONUS	= philo_bonus

RM 		= rm -f

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_FOLDERS)
	$(CC) -c -MD ${CFLAGS} $< -o $@

-include *.d

all:		${NAME}

${NAME}:	${OBJS}
			$(CC) ${CFLAGS} $(OBJS) -o $(NAME)

bonus:		${OBJS}
			$(CC) ${CFLAGS} $(OBJS) -o $(NAME_BONUS)

clean:
			${RM} ${OBJS} ${OBJS:.o=.d}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re