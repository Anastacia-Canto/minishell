/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:38:19 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/10 20:08:48 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}

int	check_cmd_name(char *line, char *name, size_t len)
{
	if (ft_strncmp(line, name, len) && ft_strlen(line) >= len)
		return (printf("%s: command not found\n", line));
	return (0);
}

int	array_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
