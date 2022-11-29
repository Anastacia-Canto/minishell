/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/11/29 18:55:27 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

// typedef struct s_words
// {
// 	struct s_list	*word;
// }	t_words;

// t_words	*words(void);
void	break_line(char *line);
void	print_list(t_list **list);
void	break_line(char *line);
void	free_list(t_list **list);

#endif