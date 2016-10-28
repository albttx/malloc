#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/05/28 16:38:24 by ale-batt          #+#    #+#             *#
#*   Updated: 2016/10/26 14:56:01 by ale-batt         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

FLAGS = -Wall -Wextra -Werror -g

LIBFT = ../libft

HEADERS		= -Iincludes/ -I$(LIBFT)/includes
C_DIR		= sources
H_DIR		= includes
O_DIR 		= .OBJS
TEST_DIR	= test

TEST_FILES 	= $(shell find $(TEST_DIR) -type f -follow)

C_FILES 	= $(shell find $(C_DIR) -type f -follow)
H_FILES 	= $(shell find $(H_DIR) -type f -follow)
O_FILES = $(C_FILES:%.c=$(O_DIR)/%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(O_DIR) $(O_FILES)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -shared -o $@ $(O_FILES) -L$(LIBFT) -lft
	@ln -sf $(NAME) libft_malloc.so

$(O_DIR)/%.o: %.c
	@gcc -o $@ -c $< $(HEADERS)

$(O_DIR):
	@mkdir -p $(O_DIR)/$(C_DIR)

clean:
	@rm -rf ./a.out
	@make clean -C $(LIBFT)
	@rm -rf $(O_DIR)


fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME)

re: fclean all

.PHONY: norme setenv unsetenv test

norme:
	norminette $(C_FILES) $(H_FILES)

setenv:
	@echo "export DYLD_LIBRARY_PATH=."
	@echo "export DYLD_INSERT_LIBRARIES=$(NAME)"
	@echo "export DYLD_FORCE_FLAT_NAMESPACE=1"
	@echo "# Run eval \$$(make setenv)"

unsetenv:
	@echo "unset DYLD_LIBRARY_PATH"
	@echo "unset DYLD_INSERT_LIBRARIES"
	@echo "unset DYLD_FORCE_FLAT_NAMESPACE"
	@echo "# Run eval \$$(make unsetenv)"

test: all
	@LD_PRELOAD=$(NAME) gcc $(FLAGS) $(HEADERS) $(C_FILES) $(LIBFT)/libft.a $(TEST_FILES)
	@./a.out

nolib: all
	@gcc $(FLAGS) $(HEADERS) $(LIBFT)/libft.a $(TEST_FILES) sources/show_alloc_memory.c
	@./a.out
