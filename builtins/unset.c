/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/27 16:22:43 by sde-mull         ###   ########.fr       */
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
		printf("%s\n", line[index]);
		if (check_value_list(line[index], data()->expo))
			data()->expo = remove_from_list(line[index], data()->expo);
		if (check_value_list(line[index], data()->env))
			data()->env = remove_from_list(line[index], data()->env);
		if (check_value_list(line[index], data()->vars))
			data()->vars = remove_from_list(line[index], data()->vars);
		index++;
	}
	return (0);
}
