.SILENT:

# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m

# Executable name
NAME = so_long

# 
INC = /usr/local/include
INCFT = ./libft/inc
LIBFT = ./libft/libft.a
LIBMLX = ./minilibx/libmlx_Linux.a ./minilibx/libmlx.a

UNAME := $(shell uname)

# Compiler options
CFLAGS = -Wall -Wextra -Werror -g -I$(INC) -I$(INCFT) -I./inc
LFLAGS = -L$(LIBMLX) $(LIBFT)

# Source and object files
SRCS =	$(wildcard ./src/*.c)
OBJS = $(SRCS:%.c=%.o)

ifeq ($(UNAME), Darwin) # iMac / iOS
	CC = gcc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC = clang
else #Linux and others
	CC = cc
	LFLAGS += -lbsd -lXext -lX11 -lm
endif

# Formatting characters
CHAR = =-=
NUM = 7
REPEATED_CHARS = $(call repeat_char,$(shell seq $(NUM)))

# Default target
$(NAME):	$(OBJS)
	if [ ! -f ./libft/libft.a ]; then \
		$(MAKE) run -C ./libft/; \
	fi
	$(MAKE) -C ./minilibx/
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
	echo "\\n$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(WHITE)	$(NAME)"
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(GREEN)SUCCESSFULLY COMPILED$(RESET)\\n"

# Build executable
all: $(NAME)

# Clean object files
clean:
	make clean -C ./libft
	rm -f $(OBJS)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Rebuild the project and remove object files
run: re
	$(MAKE) clean

# Show help message
help:
	echo "\\nUsage: make [target]\\n"
	echo "Targets:"
	echo "  all        Build executable"
	echo "  clean      Remove object files"
	echo "  fclean     Remove object files and executable"
	echo "  re         Rebuild project"
	echo "  run        Rebuild project and remove object files"

# Define repeat_char function
define repeat_char
$(strip $(if $(firstword $(1)), $(CHAR)$(call repeat_char,$(subst $(firstword $(1)),,$(1)))))
endef

.PHONY: all clean fclean re