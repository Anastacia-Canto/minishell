/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/06 01:57:31 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char *line)
{
	char	**args;
	size_t	len;
	size_t	index;

	index = 1;
	if (check_cmd_name(line, "unset ", 6))
		return (127);
	args = ft_split(line, ' ');
	len = array_len(args);
	while (index < len)
	{
		if (check_value_list(args[index], data()->expo))
			data()->expo = remove_from_list(args[index], data()->expo);
		if (check_value_list(args[index], data()->env))
			data()->env = remove_from_list(args[index], data()->env);
		if (check_value_list(args[index], data()->vars))
			data()->vars = remove_from_list(args[index], data()->vars);
		index++;
	}
	free_array(args);
	return (0);
}
