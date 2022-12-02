/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/02 16:48:39 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}	t_lst;

// typedef struct s_data
// {
// 	t_lst	*words;
// }	t_data;

// t_data	*data(void);
void	break_line(char *line);
void	print_list(t_lst *list);
void	break_line(char *line);
void	free_list(t_lst **list);
t_lst	*new_node(char *content);
t_lst	*add_back(t_lst **list, t_lst *new);
void	check_exit(char *line);
//split for whitespaces
char	**ft_split_ms(char const *s);
char	*get_str_ms(char const *s, int	*pos);
int		count_str_ms(char const *s);
#endif