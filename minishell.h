/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/04 18:44:59 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_input
{
	char	*src;
	int		size;
	int		pos;
}	t_input;

typedef struct s_data
{
	t_input	*input;
	t_list	*tokens;
}	t_data;

t_data	*data(void);
void	init_data(void);
void	break_line(char *line);
void	break_line(char *line);
void	check_exit(char *line);
//split for whitespaces
char	**ft_split_ms(char const *s);
char	*get_str_ms(char const *s, int	*pos);
int		count_str_ms(char const *s);
#endif