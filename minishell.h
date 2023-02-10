/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:46 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/10 16:44:44 by anastacia        ###   ########.fr       */
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
# include <errno.h>
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
	int		sig;
	int		break_flg;
	int		stop_wr;
	char	**args;
	int		ignore_sign;
	char	**args_p;
	int		p_args;
	char	*temp;
	int		p_temp;
}	t_data;

typedef struct s_heredoc
{
	int		index;
	int		H_file;
	int		out;
	int		in;
	char	**all_inputs;
	char	**all_outputs;
	int		input_len;
	int		output_len;
	int		i_input;
	int		i_output;
	int		i_args;
	char	**args;
	int		arg_len;
	char	*line2;
	int		here_flag;
	char	**here_str;
}	t_heredoc;

//Main---------------------------------------------------------------
void	handler_sigint(int sig);
int		check_null_line(char *line);
void	main_loop(void);
//Parser-------------------------------------------------------------
void	parser(char *line);
void	ft_split_args(char *line);
int		check_end_quote(char *line, int *pos);
int		is_quote(char c);
void	print_cmds(char ***cmds);
//Parser2------------------------------------------------------------
void	finalize_arg(void);
void	copy_arg(char *line, int *i);
void	ft_ignore(char *line, int k);
int		count_cmds(char **args);
//Parser3------------------------------------------------------------
int		check_pipe_on_args(char **args);
char	***list_cmds(char **args, int nbr_cmds);
void	free_cmds_list(char ***cmds, int nbr_cmds);
char	**split_cmds(char **line, int start, int len);
void	split_pipe(char *line, int *i);
//Lexer--------------------------------------------------------------
void	to_builtins(char **line, int *pd);
int		treat_others(char **line, int fd);
//Pipe---------------------------------------------------------------
int		ft_pipe(char ***cmds, int len);
void	ft_execute_pipe(char **cmds, int *p1, int sig);
//Exec---------------------------------------------------------------
int		ft_exec(char **line, int file);
int		exec_prog(char **line, int *fd);
char	*get_path(char *cmd_line);
void	execution(char **line, int *pd);
//Heredoc------------------------------------------------------------
void	heredoc(char **line, int *pd);
void	fix_args(char **lista);
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
void	print_args(char **args);
//Check--------------------------------------------------------------
int		check_value_list(char *str, char **lista);
int		check_line(char *str);
int		check_str(char *str);
int		check_heredoc(char **lines);
//Free---------------------------------------------------------------
void	free_exit(void);
//Heredoc_fun--------------------------------------------------------
char	*get_pfile(char *line);;
void	ft_double_less(char **line, t_heredoc *file);
void	save_heredoc(char *line, int fd);
int		check_here_args(t_heredoc *file);
void	get_here_str(char **line, t_heredoc *file);
//here_utils---------------------------------------------------------
int		ft_recmp(char *line, char *cmp);
int		input_len(char **line, t_heredoc *file);
int		output_len(char **line);
void	get_inputs(char **line, t_heredoc *file);
void	get_outputs(char **line, t_heredoc *file);
//here_utils2---------------------------------------------------------
void	get_args(char **line, t_heredoc *file);
int		open_files(char **line, t_heredoc *file);
void	execute_redirection(t_heredoc *file, int *pd);
// Echo--------------------------------------------------------------
int		ft_echo(char **line, int fd);
int		ft_echo_n(char **line, int fd);
int		check_n(char *arg);
void	print_echo(char **line, int fd, int i);
// Echo 2 -----------------------------------------------------------
void	check_special_sign(char **line);
void	change_special_sign(char **line, int i, int sig);
// Exit--------------------------------------------------------------
int		ft_exit(char **line, int fd, int *pd);
int		check_num(char *arg);
int		check_exit_args(char **args, size_t len);
// Env---------------------------------------------------------------
int		print_envs(char **env, char **line, int fd);
// Expansion
char	*get_var(char *name, char **list);
char	*check_if_env(char *arg);
char	*ft_expand_env(int dollars, char *arg);
char	*expand_cli_env(char *name, int i);
char	*get_value(char *name, int *pos);
char	*concat_env(char *s1, char *s2);
// PWD--------------------------------------------------------------
int		ft_pwd(int fd);
// CD---------------------------------------------------------------
int		ft_cd(char **line);
void	change_prompt(void);
// Export-----------------------------------------------------------
int		ft_export(char **line, int fd);
int		check_export_args(char **args, size_t len);
void	print_export(int fd);
void	print_char(char *str, int fd);
int		change_or_add(char *arg, int flg, char ***str);
// Unset------------------------------------------------------------
int		ft_unset(char **line);
void	exchange(int check, char *line);
#endif