/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:10:03 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/13 17:14:11 by anastacia        ###   ########.fr       */
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
	free_array(args);
	exit(ret);
}

int	check_exit_args(char **args)
{
	int		count;

	count = 0;
	while (args[count])
		count++;
	if (count > 2)
	{
		free_array(args);
		printf("exit: too many arguments\n");
		exit(1);
	}
	return (count);
}
