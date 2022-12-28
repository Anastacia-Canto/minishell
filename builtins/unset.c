/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:23 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/28 16:19:33 by anastacia        ###   ########.fr       */
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
