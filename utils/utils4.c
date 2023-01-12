/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:10:51 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/12 13:23:51 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmd_error(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		printf("%c", str[index++]);
	printf(": command not found\n");
	return (127);
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
