/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:07:01 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/11 16:18:51 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec(char *line)
{
	pid_t	pid;
	int		fd[2];
	int		ret;

	ret = 0;
	if (pipe(fd) == -1)
		return (1);
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
	execve(path, cmd_line, data()->env);
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
	char	*temp;
	char	**buffer;
	int		i;

	i = 0;
	path = getenv("PATH");
	buffer = ft_split(path, ':');
	cmd_line = ft_strjoin("/", cmd_line);
	while (i < array_len(buffer) - 1)
	{
		temp = ft_strjoin(buffer[i], cmd_line);
		if (access(temp, F_OK) == 0)
		{
			free(cmd_line);
			path = ft_strdup(temp);
			free_array(buffer);
			return (path);
		}
		free(temp);
		i++;
	}
	free_array(buffer);
	free(cmd_line);
	path = NULL;
	return (path);
}
