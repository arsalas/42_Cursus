# COLORS
RED				:= \033[31m
GREEN			:= \033[32m
YELLOW			:= \033[33m
BLUE			:= \033[34m
NC				:= \033[m

CC				:= gcc

# FLAGS
W_FLAGS			:= -Wall -Wextra -Werror
SANITIZER		:= -g -fsanitize=address
FLAGS			:= $(W_FLAGS) $(SANITIZER)

RM 				:= rm -f

# SRC
SRCS 	= ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin

# OBJECTS
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MP

# PROGRAM NAME
NAME 	= libft.a

# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.c

.SECONDEXPANSION:

all: $(BIN_DIR) $(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@echo "🔃 $(BLUE)Compiling" $(basename $(notdir $@)) 
	@$(CC) $(FLAGS) $(DEPFLAGS) $(INC) -c $< -o $@


$(BIN): $(OBJS)
	@ar rc $(BIN) $(OBJS)
	@echo "✅ $(GREEN)$(NAME) compiled!$(NC)"


clean:
	@echo "🧹 $(RED)$(NAME) removing...$(NC)"
	@$(RM) $(OBJS) $(DEPS)
	@echo "✅ $(GREEN)$(NAME) cleaned!$(NC)"
	@$(RM) -rf  $(OBJS_DIR)

fclean:		clean
	@$(RM) $(BIN)
	@$(RM) -rf  $(BIN_DIR)

file_clean:	
	@$(RM) $(BIN)
	@$(RM) -rf  $(BIN_DIR)

re:			fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)

.PHONY:		all clean fclean re file_clean