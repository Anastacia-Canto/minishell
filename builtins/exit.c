/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:10:03 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/13 14:43:20 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char *line)
{
	char	**args;
	int		ret;

	args = ft_split(line, ' ');
	free (line);
	rl_clear_history();
	ret = 0;
	if (check_exit_args(args))
	{
		printf("%s\n", args[0]);
		if (check_exit_args(args) == 2)
			ret = ft_atoi(args[1]);
	}
	free_exit_args(args);
	exit(ret);
}

void	free_exit_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free (args[i++]);
	free (args);
}

int	check_exit_args(char **args)
{
	int		count;

	count = 0;
	while (args[count])
		count++;
	if (count > 2)
	{
		free_exit_args(args);
		printf("exit: too many arguments\n");
		exit(1);
	}
	return (count);
}
