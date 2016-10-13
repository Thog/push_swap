# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#              #
#    Updated: 2016/09/29 11:32:25 by tguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Wall -Wextra -Werror -march=native -I./includes
PRGFLAGS = -lft
CC = gcc

NAME = push_swap
PRG1 = checker
LIB = libft
SRC = push_operations.c rotate_operations.c swap_operation.c base.c \
	  operations.c reverse_rotate_operations.c allocator.c \
	  pushback_operations.c splitter_validator.c
SRCDIR = src
OUTDIR = out
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
COMMON_OBJ = $(addprefix $(OUTDIR)/, $(SRC:.c=.o))
PUSH_SWAP_OBJ = $(COMMON_OBJ) $(OUTDIR)/$(NAME).o
CHECKER_OBJ = $(COMMON_OBJ) $(OUTDIR)/$(PRG1).o
OBJ = $(PUSH_SWAP_OBJ) $(OUTDIR)/$(PRG1).o


all: $(NAME) $(PRG1)

$(NAME): $(OUTDIR) $(PUSH_SWAP_OBJ)
	@(cd $(LIB) && $(MAKE))
	$(CC) -o $(NAME) $(CFLAGS) -I./libft -L./libft $(PUSH_SWAP_OBJ) $(PRGFLAGS)

$(PRG1): $(OUTDIR) $(CHECKER_OBJ)
	@(cd $(LIB) && $(MAKE))
	$(CC) -o $(PRG1) $(CFLAGS) -I./libft -L./libft $(CHECKER_OBJ) $(PRGFLAGS)

$(OUTDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -I $(LIB) -o $@ -c $? $(CFLAGS)

$(OUTDIR):
	@mkdir -p $(OUTDIR)

clean:
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(OBJ)
	@rm -rf $(OUTDIR)

fclean: clean
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(NAME) $(PRG1)

.PHONY: clean fclean re

re: fclean all
