/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:27:36 by ansilva-          #+#    #+#             */
/*   Updated: 2023/02/10 16:50:22 by anastacia        ###   ########.fr       */
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
	int		i;
	int		sig;

	tmpin = dup(0);
	tmpout = dup(1);
	fd[0] = dup(tmpin);
	i = -1;
	sig = 0;
	while (++i < len)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		if (i == len - 1)
		{
			fd[1] = dup(tmpout);
			pipe(p1);
			sig = 1;
		}
		else
		{
			pipe(fdpipe);
			fd[1] = fdpipe[1];
			fd[0] = fdpipe[0];
		}
		dup2(fd[1], 1);
		close (fd[1]);
		ft_execute_pipe(cmds[i], p1, sig);
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	close(p1[1]);
	read(p1[0], &data()->exit_status, sizeof(int));
	close(p1[0]);
	return (data()->exit_status);
}

void	ft_execute_pipe(char **cmds, int *p1, int sig)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execution(cmds, p1);
		if (sig)
		{
			close(p1[0]);
			write(p1[1], &data()->exit_status, sizeof(int));
			close(p1[1]);
		}
		exit(data()->exit_status);
	}
	waitpid(pid, NULL, 0);
}
