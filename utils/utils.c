/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:38:19 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/19 17:54:51 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

char	*adjust_line(char *line)
{
	char	*new_line;
	int		i;
	int		j;

	new_line = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!line || !new_line)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i] && ft_whitespace(line[i]))
		i++;
	while (line[i] && !ft_whitespace(line[i]))
		new_line[j++] = line[i++];
	if (line[i])
		new_line[j++] = line[i++];
	while (line[i] && ft_whitespace(line[i]))
		i++;
	while (line[i])
		new_line[j++] = line[i++];
	new_line[j] = '\0';
	return (new_line);
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
