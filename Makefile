# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:43:01 by anastacia         #+#    #+#              #
#    Updated: 2023/01/28 20:54:09 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = minishell

SRC = main\
	  src/lexer src/pipe src/exec src/parser src/parser2 src/parser3\
	  src/heredoc src/expansion src/expansion2\
	  utils/utils utils/utils2 utils/utils3 utils/utils4 utils/check utils/free\
	  heredoc_utils/heredoc_fun heredoc_utils/here_utils heredoc_utils/here_utils2\
	  builtins/echo builtins/exit builtins/env\
	  builtins/pwd builtins/cd builtins/export builtins/unset\

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