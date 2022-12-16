/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/16 13:41:47 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	**env;
	char	*prompt;
}	t_data;

t_data	*data(void);
// Utils
void	break_line(char *line);
char	*fix_spaces(char *line);
void	free_array(char **arr);
int		check_cmd_name(char *line, char *name, size_t len);
int		array_len(char **arr);
//Builtins
void	to_builtins(char *line);
// ------------------- echo----------------------
int		ft_echo(char *line);
void	printer(char *line, size_t pos);
// ------------------- exit----------------------
int		ft_exit(char *line);
int		check_num(char *arg);
int		check_exit_args(char **args, size_t len);
// ------------------- env-----------------------
int		ft_expand_env(char *line, size_t *pos);
void	print_envs(char **env, char *line);
// ------------------- pwd-----------------------
int		ft_pwd(char *line);
// ------------------- cd------------------------
int		ft_cd(char *line);
void	change_prompt(void);
// -------------------export---------------------
int		ft_export(char *line);
void	check_export_args(char **args, size_t len);
#endif