# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:43:01 by anastacia         #+#    #+#              #
#    Updated: 2022/12/20 03:10:42 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = minishell

SRC = main\
	  src/lexer\
	  utils/utils utils/utils2 utils/utils3 utils/check\
	  builtins/echo builtins/exit builtins/env\
	  builtins/pwd builtins/cd builtins/export\

LIBFT = libft/libft.a
LIBFT_PATH = ./libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I. -fsanitize=address
LFLAGS = -lreadline

all: $(NAME)

$(NAME): $(LIBFT) $(SRC:=.o)
	$(CC) $(CFLAGS) $(SRC:=.o) $(LIBFT) -o $(NAME) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(NAME) $(SRC:=.o)

fclean: clean
	$(RM) $(LIBFT)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re