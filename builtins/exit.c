/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:10:03 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/20 18:15:15 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char *line)
{
	char	**args;
	int		ret;
	size_t	len;

	if (check_cmd_name(line, "exit ", 5))
		return (127);
	args = ft_split(line, ' ');
	len = array_len(args);
	ret = 0;
	if (check_exit_args(args, len))
		return (1);
	printf("%s\n", args[0]);
	if (args[1])
		ret = ft_atoi(args[1]);
	free_array(args);
	free (line);
	rl_clear_history();
	exit (ret % 256);
}

int	check_exit_args(char **args, size_t len)
{
	if (len > 1)
	{
		if (check_num(args[1]))
		{
			rl_clear_history();
			free_array(args);
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
