/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/28 21:41:39 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **line)
{
	size_t	len;
	size_t	index;

	index = 1;
	len = array_len(line);
	while (index < len)
	{
		if (check_value_list(line[index], data()->expo) != 1)
			exchange(1, line[index]);
		if (check_value_list(line[index], data()->env) != 1)
			exchange(2, line[index]);
		if (check_value_list(line[index], data()->vars) != 1)
			exchange(3, line[index]);
		index++;
	}
	return (0);
}

void	exchange(int check, char *line)
{
	char **expo;
	char **vars;
	char **env;

	if (check == 1)
	{
		expo = remove_from_list(line, data()->expo);
		data()->expo = expo;
	}
	if (check == 2)
	{
		env = remove_from_list(line, data()->env);
		data()->env = env;
	}
	if (check == 3)
	{
		vars = remove_from_list(line, data()->vars);
		data()->vars = vars;
	}
}
