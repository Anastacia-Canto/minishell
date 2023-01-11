/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/11 09:07:52 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	break_in_cmd(char *line)
{
	char	**cmds;
	int		len;
	int		exit;

	data()->pipe_flag = 0;
	cmds = ft_split(line, '|');
	len = array_len(cmds);
	free (line);
	if (len > 1)
		exit = ft_pipe(cmds, len);
	else
		exit = prep_exec(cmds[0], 1, NULL);
	free_array(cmds);
	data()->exit_status = exit;
}

void	to_builtins(char *line, int fd, int *pd)
{
	int	exit;

	if (!ft_strncmp(line, "echo -n", 7))
		exit = ft_echo_n(line, fd);
	else if (!ft_strncmp(line, "echo", 4))
		exit = ft_echo(line, fd);
	else if (!ft_strncmp(line, "pwd", 3))
		exit = ft_pwd(line, fd);
	else if (!ft_strncmp(line, "cd", 2))
		exit = ft_cd(line);
	else if (!ft_strncmp(line, "env", 3))
		exit = print_envs(data()->env, line, fd);
	else if (!ft_strncmp(line, "exit", 4))
		exit = ft_exit(line, fd, pd);
	else if (!ft_strncmp(line, "export", 6))
		exit = ft_export(line, fd);
	else if (!ft_strncmp(line, "unset", 5))
		exit = ft_unset(line);
	else
		exit = treat_others(line);
	data()->exit_status = exit;
}

int	treat_others(char *line)
{
	int		ret;

	ret = 0;
	if (!check_line(line))
		return (add_var(line));
	ret = ft_exec(line);
	return (ret);
}
