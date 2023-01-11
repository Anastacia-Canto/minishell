/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/11 03:20:03 by sde-mull         ###   ########.fr       */
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
	if ( len > 1)
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

int	ft_exec(char *line)
{
	pid_t	pid;
	int		fd[2];
	int		ret;

	ret = 0;
	if (pipe(fd) == -1)
		return 1;
	pid = fork();
	if (pid == 0)
	{
		ret = exec_prog(line, fd);
		exit(ret);
	}
	else
	{
		if (waitpid(pid, &ret, 0) != pid)
			ret = -1;
		close(fd[1]);
		read(fd[0], &ret, sizeof(int));
		close(fd[0]);
	}
	return (ret);
}

int	exec_prog(char *line, int *fd)
{
	char	**cmd_line;
	int		ret;
	char	*path;

	close(fd[0]);
	ret = 0;
	cmd_line = ft_split(line, ' ');
	path = ft_strdup(cmd_line[0]);
	if (ft_strncmp(line, "./", 2))
	{
		free (path);
		path = get_path(cmd_line[0]);
	}
	if (execve(path, cmd_line, data()->env) == -1)
		ret = get_cmd_error(line);
	free_array(cmd_line);
	free (path);
	write(fd[1], &ret, sizeof(int));
	close(fd[1]);
	return (ret);
}

char	*get_path(char *cmd_line)
{
	char	*path;
	char	**buffer;
	int		i;

	i = 0;
	path = getenv("PATH");
	buffer = ft_split(path, ':');
	cmd_line = ft_strjoin("/", cmd_line);
	while (i < array_len(buffer))
	{
		buffer[i] = ft_strjoin(buffer[i], cmd_line);
		if (access(buffer[i], F_OK) == 0)
		{
			free(cmd_line);
			path = buffer[i];
			return (path);
		}
		i++;
	}
	free(cmd_line);
	path = buffer[i - 1];
	return (path);
}