/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:10:51 by sde-mull          #+#    #+#             */
/*   Updated: 2023/02/10 11:54:38 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmd_error(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		write(2, &str[index++], 1);
	write(2, ": command not found\n", 20);
	return (32512);
}

int	add_var(char *line)
{
	if (check_value_list(line, data()->expo) == 2)
		change_or_add(line, 1, &data()->expo);
	if (check_value_list(line, data()->env) == 2)
		change_or_add(line, 1, &data()->env);
	change_or_add(line, 1, &data()->vars);
	return (0);
}

void	print_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		printf("args[%d]: %s\n len: %ld\n", i, args[i], ft_strlen(args[i]));
}
