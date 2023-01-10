/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:27:36 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/10 09:28:58 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(char **cmds)
{
	int		tmpin;
	int		tmpout;
	int		fd[2];
	pid_t	pid;
	int		i;

	tmpin = dup(0);
	tmpout = dup(1);
	i = -1;
	while (++i < array_len(cmds))
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		if (i == array_len(cmds) - 1)
			fd[1] = dup(tmpout);
		else
			pipe(fd);
		dup2(fd[1], 1);
		close (fd[1]);
		pid = fork();
		if (pid == 0)
		{
			data()->exit_status = prep_exec(cmds[i]);
			exit(data()->exit_status);
		}
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	waitpid(pid, NULL, 0);
	return (data()->exit_status);
}

int	prep_exec(char *cmd)
{
	char	*adjusted_line;
	int		ret;

	adjusted_line = adjust_line(cmd);
	adjusted_line = check_if_env(adjusted_line);
	to_builtins(adjusted_line, 1);
	free (adjusted_line);
	ret = data()->exit_status;
	return (ret);
}
