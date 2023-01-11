/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:10:03 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/11 12:15:09 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char *line, int fd, int *pd)
{
	char	**args;
	int		ret;
	size_t	len;

	if (check_cmd_name(line, "exit ", 5))
		return (127);
	args = ft_split(line, ' ');
	free (line);
	len = array_len(args);
	ret = 0;
	if (check_exit_args(args, len))
		return (1);
	if (pd == NULL)
		write(fd, "exit\n", 5);
	if (args[1])
		ret = ft_atoi(args[1]);
	free_array(args);
	free_exit();
	rl_clear_history();
	ret = ret % 256;
	if (pd != NULL)
	{
		close(pd[0]);
		write(pd[1], &ret, sizeof(int));
		close(pd[1]);
	}
	exit (ret);
}

int	check_exit_args(char **args, size_t len)
{
	if (len > 1)
	{
		if (check_num(args[1]))
		{
			clear_history();
			free_array(args);
			free_exit();
			exit(2);
		}
		if (len > 2)
		{
			free_array(args);
			printf("exit\nminishell: exit: too many arguments\n");
			return (1);
		}
	}
	return (0);
}

int	check_num(char *arg)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(arg) && ft_isdigit(arg[i]) != 0)
		i++;
	if (i < ft_strlen(arg))
	{
		printf("exit\nminishell: exit: %s: numeric argument required\n", arg);
		return (2);
	}
	return (0);
}
