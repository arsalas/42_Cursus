CFLAGS 	= -Wall -Wextra -Werror -pthread -Iinclude
CC		= gcc

DIR		= philo
DIR_B	= philo_bonus
SRC_DIR = src
OBJ_DIR = obj

F_JOB = jobs
F_UTILS = utils
F_ACTIONS = actions

FOLDERS = $(DIR)/$(F_JOB) \
		$(DIR)/$(F_UTILS) \
		$(DIR)/$(F_ACTIONS) \

FOLDERS_B = $(DIR_B)/$(F_JOB) \
			$(DIR_B)/$(F_UTILS) \
			$(DIR_B)/$(F_ACTIONS) \

OBJ_FOLDERS = $(DIR)/$(OBJ_DIR)/$(F_JOB) \
			$(DIR)/$(OBJ_DIR)/$(F_UTILS) \
			$(DIR)/$(OBJ_DIR)/$(F_ACTIONS) \

OBJ_FOLDERS_B = $(DIR_B)/$(OBJ_DIR)/$(F_JOB) \
				$(DIR_B)/$(OBJ_DIR)/$(F_UTILS) \
				$(DIR_B)/$(OBJ_DIR)/$(F_ACTIONS) \

SRCS 	= $(DIR)/$(SRC_DIR)/main.c \
		$(DIR)/$(SRC_DIR)/$(F_JOB)/thread.c \
		$(DIR)/$(SRC_DIR)/$(F_UTILS)/init.c \
		$(DIR)/$(SRC_DIR)/$(F_UTILS)/args.c \
		$(DIR)/$(SRC_DIR)/$(F_UTILS)/utils.c \
		$(DIR)/$(SRC_DIR)/$(F_ACTIONS)/die.c \
		$(DIR)/$(SRC_DIR)/$(F_ACTIONS)/eat.c \
		$(DIR)/$(SRC_DIR)/$(F_ACTIONS)/fork.c \
		$(DIR)/$(SRC_DIR)/$(F_ACTIONS)/sleep.c \

OBJS 	= $(DIR)/$(OBJ_DIR)/main.o \
		$(DIR)/$(OBJ_DIR)/$(F_JOB)/thread.o \
		$(DIR)/$(OBJ_DIR)/$(F_UTILS)/init.o \
		$(DIR)/$(OBJ_DIR)/$(F_UTILS)/args.o \
		$(DIR)/$(OBJ_DIR)/$(F_UTILS)/utils.o \
		$(DIR)/$(OBJ_DIR)/$(F_ACTIONS)/die.o \
		$(DIR)/$(OBJ_DIR)/$(F_ACTIONS)/eat.o \
		$(DIR)/$(OBJ_DIR)/$(F_ACTIONS)/fork.o \
		$(DIR)/$(OBJ_DIR)/$(F_ACTIONS)/sleep.o \

SRCS_B	= $(DIR_B)/$(SRC_DIR)/main.c \
		$(DIR_B)/$(SRC_DIR)/$(F_JOB)/process.c \
		$(DIR_B)/$(SRC_DIR)/$(F_UTILS)/args.c \
		$(DIR_B)/$(SRC_DIR)/$(F_UTILS)/init.c \
		$(DIR_B)/$(SRC_DIR)/$(F_UTILS)/utils.c \
		$(DIR_B)/$(SRC_DIR)/$(F_ACTIONS)/die.c \
		$(DIR_B)/$(SRC_DIR)/$(F_ACTIONS)/eat.c \
		$(DIR_B)/$(SRC_DIR)/$(F_ACTIONS)/fork.c \
		$(DIR_B)/$(SRC_DIR)/$(F_ACTIONS)/sleep.c \

OBJS_B 	= $(DIR_B)/$(OBJ_DIR)/main.o \
		$(DIR_B)/$(OBJ_DIR)/$(F_JOB)/process.o \
		$(DIR_B)/$(OBJ_DIR)/$(F_UTILS)/args.o \
		$(DIR_B)/$(OBJ_DIR)/$(F_UTILS)/init.o \
		$(DIR_B)/$(OBJ_DIR)/$(F_UTILS)/utils.o \
		$(DIR_B)/$(OBJ_DIR)/$(F_ACTIONS)/die.o \
		$(DIR_B)/$(OBJ_DIR)/$(F_ACTIONS)/eat.o \
		$(DIR_B)/$(OBJ_DIR)/$(F_ACTIONS)/fork.o \
		$(DIR_B)/$(OBJ_DIR)/$(F_ACTIONS)/sleep.o \


NAME		= philo

NAME_BONUS	= philo_bonus

RM 			= rm -f

$(DIR)/$(OBJ_DIR)/%.o : $(DIR)/$(SRC_DIR)/%.c
	mkdir -p $(OBJ_FOLDERS)
	$(CC) -c -MD ${CFLAGS} $< -o $@

-include *.d

$(DIR_B)/$(OBJ_DIR)/%.o : $(DIR_B)/$(SRC_DIR)/%.c
	mkdir -p $(OBJ_FOLDERS_B)
	$(CC) -c -MD ${CFLAGS} $< -o $@

-include *.d

all:		${NAME}

${NAME}:	${OBJS}
			$(CC) ${CFLAGS} $(OBJS) -o $(DIR)/$(NAME)

bonus:		${OBJS_B}
			$(CC) ${CFLAGS} $(OBJS_B) -o $(DIR_B)/$(NAME_BONUS)

clean:
			${RM} ${OBJS} ${OBJS:.o=.d}
			${RM} ${OBJS_B} ${OBJS_B:.o=.d}

fclean:		clean
			${RM} $(DIR)/${NAME}
			${RM} $(DIR_B)/${NAME_BONUS}

re:			fclean all

.PHONY:		all clean fclean re bonus