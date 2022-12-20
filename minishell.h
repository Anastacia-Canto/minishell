/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/20 08:38:47 by anastacia        ###   ########.fr       */
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
	int		exit_status;
	char	**expo;
	int		expo_flag;
}	t_data;

t_data	*data(void);
// Utils
void	break_line(char *line);
char	*adjust_line(char *line);
void	free_array(char **arr);
int		check_cmd_name(char *line, char *name, size_t len);
int		array_len(char **arr);
//Utils2
char	**ft_list(char **ex_list);
void	ft_alphabetic(char **copy);
void	ft_swap_alpha(char **copy, size_t i, size_t j);
void	init_values(char **env);
char	**add_to_list(char *str, char **lista);
//Utils3
int		find_equal(char *str, char *lista_str);
char	**change_list(char *str, char **lista);
char	**remove_from_list(char *str, char **lista);
//Check
int		check_value_list(char *str, char **lista);
// void	check_list(int check, char **lista);
int		check_str(char *str);
//Builtins
void	to_builtins(char *line);
// ------------------- echo----------------------
int		ft_echo(char *line);
int		ft_echo_n(char *line);
void	echo_dollar(char *line, size_t *pos);
void	printer(char *line);
// ------------------- exit----------------------
int		ft_exit(char *line);
int		check_num(char *arg);
int		check_exit_args(char **args, size_t len);
// ------------------- env-----------------------
int		ft_expand_env(char *line, size_t **pos);
int		print_envs(char **env, char *line);
// ------------------- pwd-----------------------
int		ft_pwd(char *line);
// ------------------- cd------------------------
int		ft_cd(char *line);
void	change_prompt(void);
// -------------------export---------------------
int		ft_export(char *line);
int		check_export_args(char **args, size_t len);
void	print_export(void);
void	print_char(char *str);
void	change_or_add(char *arg);
#endif