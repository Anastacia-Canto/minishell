/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/09 17:24:25 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

// t_data	*data(void);
void	break_line(char *line);
char	*fix_spaces(char *line);
//Builtins
void	to_builtins(char *line);
int		ft_echo(char *line);
int		check_option(char *line, size_t *pos);
int		ft_exit(char *line);
int		ft_expand_env(char *line, size_t *pos);
int		ft_pwd(void);
#endif