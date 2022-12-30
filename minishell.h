/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/30 14:48:03 by anastacia        ###   ########.fr       */
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
	char	**vars;
	int		expo_flag;
	int		expand;
}	t_data;

typedef struct s_args
{
	char			*content;
	struct s_args	*next;
}	t_args;

t_data	*data(void);
int		ft_exec(char *line);
int		exec_progm(char *line);
int		treat_others(char *line);
//Lexer
void	break_in_cmd(char *line);
void	to_builtins(char *line);
// Utils
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
int		ft_strcmp_expo(char *str, char *str2);
char	**create_list(char *str);
//Utils4
int		get_cmd_error(char *str);
int		add_var(char *line);
//Check
int		check_value_list(char *str, char **lista);
int		check_line(char *str);
int		check_str(char *str);
//Free
void	free_exit(void);
// ------------------- echo----------------------
int		ft_echo(char *line);
int		ft_echo_n(char *line);
int		echo_dollar(char *line, size_t *pos);
int		printer(char *line);
int		is_quote(char c);
void	args_parser(char *line);
int		check_end_quote(char *line, int *pos);
int		check_args(char *line);
void	split_args(char *line);
void	get_quoted_arg(char *line, int *pos);
void	get_arg(char *line, int *pos);
// ------------------- exit----------------------
int		ft_exit(char *line);
int		check_num(char *arg);
int		check_exit_args(char **args, size_t len);
// ------------------- env-----------------------
int		ft_expand_env(char *line, size_t **pos);
int		print_envs(char **env, char *line);
char	*get_var(char *name, int id);
void	print_env_value(char *value);
char	*check_if_env(char *name);
char	*expand_cli_env(char *name, int dollars);
char	*get_value(char *name, int *pos);
char	*concat_env(char *s1, char *s2);
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
int		change_or_add(char *arg, int flg, char ***str);
// --------------------unset---------------------
int		ft_unset(char *line);
#endif