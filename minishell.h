/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/11 12:21:32 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <editline/readline.h>
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
	int		pipe_flag;
}	t_data;

typedef struct s_args
{
	char			*content;
	struct s_args	*next;
}	t_args;

//Main---------------------------------------------------------------
void	handler_sigint(int sig);
int		check_null_line(char *line);
//Lexer--------------------------------------------------------------
void	break_in_cmd(char *line);
void	to_builtins(char *line, int fd, int *pd);
int		treat_others(char *line);
//Pipe---------------------------------------------------------------
int		ft_pipe(char **cmds, int len);
int		prep_exec(char *cmd, int fd, int *pd);
//Exec---------------------------------------------------------------
int		ft_exec(char *line);
int		exec_prog(char *line, int *fd);
char	*get_path(char *cmd_line);
// Utils-------------------------------------------------------------
t_data	*data(void);
char	*adjust_line(char *line);
void	free_array(char **arr);
int		check_cmd_name(char *line, char *name, size_t len);
int		array_len(char **arr);
//Utils2-------------------------------------------------------------
char	**ft_list(char **ex_list);
void	ft_alphabetic(char **copy);
void	ft_swap_alpha(char **copy, size_t i, size_t j);
void	init_values(char **env);
char	**add_to_list(char *str, char **lista);
//Utils3-------------------------------------------------------------
int		find_equal(char *str, char *lista_str);
char	**change_list(char *str, char **lista);
char	**remove_from_list(char *str, char **lista);
int		ft_strcmp_expo(char *str, char *str2);
char	**create_list(char *str);
//Utils4-------------------------------------------------------------
int		get_cmd_error(char *str);
int		add_var(char *line);
//Check--------------------------------------------------------------
int		check_value_list(char *str, char **lista);
int		check_line(char *str);
int		check_str(char *str);
//Free---------------------------------------------------------------
void	free_exit(void);
// Echo--------------------------------------------------------------
int		ft_echo(char *line, int fd);
int		ft_echo_n(char *line, int fd);
int		echo_dollar(char *line, size_t *pos, int fd);
int		printer(char *line, int fd);
int		is_quote(char c);
void	args_parser(char *line, int fd);
int		check_end_quote(char *line, int *pos);
int		check_args(char *line);
void	split_args(char *line, int fd);
void	get_quoted_arg(char *line, int *pos, int fd);
void	get_arg(char *line, int *pos, int fd);
// Exit--------------------------------------------------------------
int		ft_exit(char *line, int fd, int *pd);
int		check_num(char *arg);
int		check_exit_args(char **args, size_t len);
// Env---------------------------------------------------------------
int		ft_expand_env(char *line, size_t **pos, int fd);
int		print_envs(char **env, char *line, int fd);
char	*get_var(char *name, int id);
void	print_env_value(char *value, int fd);
char	*check_if_env(char *name);
char	*expand_cli_env(char *name, int dollars);
char	*get_value(char *name, int *pos);
char	*concat_env(char *s1, char *s2);
// PWD--------------------------------------------------------------
int		ft_pwd(char *line, int fd);
// CD---------------------------------------------------------------
int		ft_cd(char *line);
void	change_prompt(void);
// Export-----------------------------------------------------------
int		ft_export(char *line, int fd);
int		check_export_args(char **args, size_t len);
void	print_export(int fd);
void	print_char(char *str, int fd);
int		change_or_add(char *arg, int flg, char ***str);
// Unset------------------------------------------------------------
int		ft_unset(char *line);
#endif