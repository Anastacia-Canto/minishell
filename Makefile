# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:43:01 by anastacia         #+#    #+#              #
#    Updated: 2022/12/05 16:04:50 by ansilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = minishell

SRC = main\
	  src/lexer\
	  utils/utils\
	  utils/ft_split_ms\

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