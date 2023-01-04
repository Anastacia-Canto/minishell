/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/04 14:23:44 by ansilva-         ###   ########.fr       */
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
	else
		data()->exit_status = treat_others(line);
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
	path = ft_strjoin("/bin/", cmd_line[0]);
	if (execve(path, cmd_line, NULL) == -1)
		ret = get_cmd_error(line);
	free_array(cmd_line);
	free (path);
	write(fd[1], &ret, sizeof(int));
	close(fd[1]);
	return (ret);
}