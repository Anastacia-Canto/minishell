// int	ft_pipe(char **cmds)
// {
// 	int		tmpin;
// 	int		tmpout;
// 	int		fd[2];
// 	pid_t	pid;
// 	int		i;

// 	tmpin = dup(0);
// 	tmpout = dup(1);
// 	i = -1;
// 	while (++i < array_len(cmds))
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		if (i == array_len(cmds) - 1)
// 			fd[1] = dup(tmpout);
// 		else
// 			pipe(fd);
// 		dup2(fd[1], 1);
// 		close (fd[1]);
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			data()->exit_status = prep_exec(cmds[i]);
// 			exit(data()->exit_status);
// 		}
// 	}
// 	dup2(tmpin, 0);
// 	dup2(tmpout, 1);
// 	close(tmpin);
// 	close(tmpout);
// 	waitpid(pid, NULL, 0);
// 	return (data()->exit_status);
// }


// int	ft_pipe(char **cmds, int len)
// {
// 	int		tmpin;
// 	int		tmpout;
// 	int		fd[len - 1][2];
// 	pid_t	pid[len];
// 	int		i;

// 	tmpin = dup(0);
// 	tmpout = dup(1);
// 	i = -1;
// 	while (++i < len - 1)
// 	{
// 		dup2(fd[i][0], STDIN_FILENO);
// 		close(fd[i][0]);
// 		if (i == len - 2)
// 			fd[i][1] = dup(tmpout);
// 		else
// 			pipe(fd[i]);
// 		dup2(fd[i][1], 1);
// 		close (fd[i][1]);
// 	}
// 	i = -1;
// 	while (++i < len - 1)
// 		pid[i] = fork();
// 	ft_putnbr_fd(i, 2);
// 	if (pid[i - 1] == 0)
// 	{
// 		data()->exit_status = prep_exec(cmds[i - 1]);
// 		exit(data()->exit_status);
// 	}
// 	else
// 	{
// 		fd[i - 1][1] = dup(tmpout);
// 		close (fd[i - 1][1]);
// 		data()->exit_status = prep_exec(cmds[i]);
// 	}
// 	dup2(tmpin, 0);
// 	dup2(tmpout, 1);
// 	close(tmpin);
// 	close(tmpout);
// 	i = -1;
// 	while (++i < len - 1)
// 		wait(NULL);
// 	return (data()->exit_status);
// }