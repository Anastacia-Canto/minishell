/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:27:36 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/09 18:10:56 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe(char **cmds)
{
	// (void)cmds;
	char	*adjusted_line;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		i;
	
	i = 0;
	pipe(fd);
	// fd[1] = open("output.txt", O_RDWR | O_CREAT, 0777);
	data()->pipe_flag = 1;
	pid1 = fork();
	//printf("waiting 2\n");
	if (pid1 == 0)
	{
		adjusted_line = adjust_line(cmds[i]);
		// printf("input %s\n", cmds[i]);
		adjusted_line = check_if_env(adjusted_line);
		to_builtins(adjusted_line, 1);
		dup2(fd[1], STDOUT_FILENO);
		free (adjusted_line);
		close(fd[0]);
		close(fd[1]);
		// execlp("ping", "ping","-c", "5", "google.com", NULL);
		exit(0);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		adjusted_line = adjust_line(cmds[++i]);
		// printf("input %s\n", cmds[i]);
		adjusted_line = check_if_env(adjusted_line);
		
		to_builtins(adjusted_line, 1);
		free (adjusted_line);
		close(fd[0]);
		close(fd[1]);
		// execlp("grep", "grep", "rtt", NULL);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	printf("waiting 2\n");
	return ;
}