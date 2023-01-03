/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/03 15:17:28 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	break_in_cmd(char *line)
{
	char	*adjusted_line;
	char	**cmds;
	int		i;

	cmds = ft_split(line, '|');
	free (line);
	i = 0;
	while (cmds[i])
	{
		adjusted_line = adjust_line(cmds[i++]);
		adjusted_line = check_if_env(adjusted_line);
		to_builtins(adjusted_line);
		free (adjusted_line);
	}
	free_array(cmds);
}

void	to_builtins(char *line)
{
	if (!ft_strncmp(line, "echo -n", 7))
		data()->exit_status = ft_echo_n(line);
	else if (!ft_strncmp(line, "echo", 4))
		data()->exit_status = ft_echo(line);
	else if (!ft_strncmp(line, "pwd", 3))
		data()->exit_status = ft_pwd(line);
	else if (!ft_strncmp(line, "cd", 2))
		data()->exit_status = ft_cd(line);
	else if (!ft_strncmp(line, "env", 3))
		data()->exit_status = print_envs(data()->env, line);
	else if (!ft_strncmp(line, "exit", 4))
		data()->exit_status = ft_exit(line);
	else if (!ft_strncmp(line, "export", 6))
		data()->exit_status = ft_export(line);
	else if (!ft_strncmp(line, "unset", 5))
		data()->exit_status = ft_unset(line);
	else if (!ft_strncmp(line, "./", 2) || !ft_strncmp(line, "bash", 4))
		data()->exit_status = ft_exec(line);
	else
		data()->exit_status = treat_others(line);
}

int	treat_others(char *line)
{
	char	**cmd_line;
	int		ret;
	char	*path;
	pid_t	pid;

	ret = 0;
	if (!check_line(line))
		return (add_var(line));
	pid = fork();
	if (pid == 0)
	{
		cmd_line = ft_split(line, ' ');
		path = ft_strjoin("/bin/", cmd_line[0]);
		if (execve(path, cmd_line, NULL) == -1)
			ft_exit(line);
		free_array(cmd_line);
		free (path);
	}
	else
	{
		if (waitpid(pid, &ret, 0) != pid)
			ret = -1;
	}
	return (ret);
}

int	ft_exec(char *line)
{
	int		i;
	int		ret;
	char	*new_line;

	ret = 0;
	i = 0;
	if (!ft_strncmp(line, "./", 2) || !ft_strncmp(line, "bash ./", 7))
	{
		while (line[i] && line[i] != '/')
			i++;
	}
	else if (!ft_strncmp(line, "bash", 4))
	{
		while (line[i] && !ft_whitespace(line[i]))
			i++;
	}
	new_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	ret = exec_progm(new_line);
	free (new_line);
	return (ret);
}

int	exec_progm(char *line)
{
	int		ret;
	char	*new_line;
	char	*path;
	char	**args;
	int		i;
	pid_t	pid;

	ret = 0;
	i = ft_strlen(line);
	while (i >= 0 && line[i] != '/')
		i--;
	new_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	args = ft_split(new_line, ' ');
	i = 0;
	while (line[i] && !ft_whitespace(line[i]))
		i++;
	path = ft_substr(line, 0, i);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, NULL) == -1)
			ft_exit(line);
	}
	else
	{
		if (waitpid(pid, &ret, 0) != pid)
			ret = -1;
		free (new_line);
		free (path);
		free_array(args);
	}
	return (ret);
}
