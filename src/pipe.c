/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:27:36 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/10 08:44:18 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe(char **cmds)
{
	char	*adjusted_line;
	int		tmpin;
	int		tmpout;
	int		fdin;
	int		fdout;
	int		fd[2];
	pid_t	pid;
	int		i;

	tmpin = dup(0);
	tmpout = dup(1);
	fdin = dup(tmpin);
	i = 0;
	while (i < array_len(cmds))
	{
		dup2(fdin, STDIN_FILENO);
		close(fdin);
		if (i == array_len(cmds) - 1)
			fdout = dup(tmpout);
		else
		{
			pipe(fd);
			fdout = fd[1];
			fdin = fd[0];
		}
		dup2(fdout, 1);
		close (fdout);
		pid = fork();
		if (pid == 0)
		{
			adjusted_line = adjust_line(cmds[i]);
			adjusted_line = check_if_env(adjusted_line);
			to_builtins(adjusted_line, 1);
			free (adjusted_line);
			exit(0);
		}
		i++;
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	waitpid(pid, NULL, 0);
}
