/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/28 21:14:28 by sde-mull         ###   ########.fr       */
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
		printf("%s |||\n", line[index]);
		printf("its me %d\n", check_value_list(line[index], data()->expo));
		if (check_value_list(line[index], data()->expo) != 1)
			data()->expo = remove_from_list(line[index], data()->expo);
		if (check_value_list(line[index], data()->env) != 1)
			data()->env = remove_from_list(line[index], data()->env);
		if (check_value_list(line[index], data()->vars) != 1)
			data()->vars = remove_from_list(line[index], data()->vars);
		index++;
	}
	return (0);
}
