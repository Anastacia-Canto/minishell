/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:27:36 by ansilva-          #+#    #+#             */
/*   Updated: 2023/02/10 11:54:58 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(char ***cmds, int len)
{
	int		tmpin;
	int		tmpout;
	int		fd[2];
	int		p1[2];
	int		fdpipe[2];
	pid_t	pid;
	int		i;

	tmpin = dup(0);
	tmpout = dup(1);
	fd[0] = dup(tmpin);
	i = -1;
	while (++i < len)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		if (i == len - 1)
		{
			fd[1] = dup(tmpout);
			pipe(p1);
		}
		else
		{
			pipe(fdpipe);
			fd[1] = fdpipe[1];
			fd[0] = fdpipe[0];
		}
		dup2(fd[1], 1);
		close (fd[1]);
		pid = fork();
		if (pid == 0)
		{
			execution(cmds[i], p1);
			if (i == len - 1)
			{
				close(p1[0]);
				write(p1[1], &data()->exit_status, sizeof(int));
				close(p1[1]);
			}
			exit(data()->exit_status);
		}
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	close(p1[1]);
	read(p1[0], &data()->exit_status, sizeof(int));
	close(p1[0]);
	waitpid(pid, NULL, 0);
	return (data()->exit_status);
}
