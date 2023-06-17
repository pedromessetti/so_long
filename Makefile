.SILENT:

# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m

# Executable name
NAME = so_long

# Compiler options
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LDFLAGS = -I inc -g

# Source and object files
SRCS = src/main.c 
OBJS = $(SRCS:.c=.o)

# Formatting characters
CHAR = =-=
NUM = 7
REPEATED_CHARS = $(call repeat_char,$(shell seq $(NUM)))

# Default target
$(NAME):	$(OBJS)
	if [ ! -f ./libft/libft.a ]; then \
		$(MAKE) run -C ./libft/; \
	fi
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	echo "\\n$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(WHITE)	$(NAME)"
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(GREEN)SUCCESSFULLY COMPILED$(RESET)\\n"

# Build pipex executable
all: $(NAME)

# Clean object files
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME) ./libft/libft.a

# Rebuild the project
re: fclean all

# Rebuild the project and remove object files
run: re
	$(MAKE) clean

bonus: $(OBJS_BONUS)
	if [ ! -f ./libft/libft.a ]; then \
		$(MAKE) run -C ./libft/; \
	fi
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) -L./libft -lft -o $(NAME)
	echo "$(GREEN)[OK] $(WHITE)BONUS$(RESET)" 


# Define repeat_char function
define repeat_char
$(strip $(if $(firstword $(1)), $(CHAR)$(call repeat_char,$(subst $(firstword $(1)),,$(1)))))
endef