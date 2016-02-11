#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             *#
#*   Updated: 2015/12/02 19:47:24 by tguillem         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CFLAGS = -g -Wall -Wextra -Werror -I./includes
CC = gcc

NAME = push_swap
SRC = main.c operations.c algo.c val.c
SRCDIR = src
OUTDIR = out
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OUTDIR)/, $(SRC:.c=.o))
all: $(NAME)

$(NAME): mkOut $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)
$(OUTDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $? $(CFLAGS)

mkOut:
	@mkdir -p $(OUTDIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OUTDIR)

fclean: clean
	@rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
