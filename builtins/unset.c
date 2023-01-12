/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/12 14:54:18 by anastacia        ###   ########.fr       */
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
