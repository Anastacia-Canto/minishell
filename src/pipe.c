/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:27:36 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/10 17:28:47 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(char **cmds, int len)
{
	int		tmpin;
	int		tmpout;
	int		fd[2];
	int		p1[2];
	pid_t	pid;
	int		i;

	tmpin = dup(0);
	tmpout = dup(1);
	i = -1;
	while (++i < len)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		if (i == len - 1)
		{
			fd[1] = dup(tmpout);
			pipe(p1);
		}
		else
			pipe(fd);
		dup2(fd[1], 1);
		close (fd[1]);
		pid = fork();
		if (pid == 0)
		{
			data()->exit_status = prep_exec(cmds[i], 1, p1);
			if (i == len -1)
			{
				close(p1[0]);
				write(p1[1], &data()->exit_status, sizeof(int));
				close(p1[1]);
			}
			exit(data()->exit_status);
		}
	}
	close(p1[1]);
	read(p1[0], &data()->exit_status, sizeof(int));
	close(p1[0]);
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	waitpid(pid, NULL, 0);
	return (data()->exit_status);
}

int	prep_exec(char *cmd, int fd, int *pd)
{
	char	*adjusted_line;
	int		ret;

	adjusted_line = adjust_line(cmd);
	adjusted_line = check_if_env(adjusted_line);
	to_builtins(adjusted_line, fd, pd);
	free (adjusted_line);
	ret = data()->exit_status;
	return (ret);
}
