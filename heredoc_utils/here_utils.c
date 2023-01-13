/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:11:09 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/13 09:27:39 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pfile(char *line)
{
	char	*path;
	char	*temp;

	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		return (NULL);
	temp = ft_strdup(path);
	temp = ft_strjoin(temp, "/");
	temp = ft_strjoin(temp, line);
	free(path);
	return (temp);
}

void	get_args(char **line, int len, t_heredoc *file)
{
	int	index;

	index = 0;
	file->print_args = malloc(sizeof(char *) * len);
	while (index < len - 1)
	{
		file->print_args[index] = ft_strdup(line[index]);
		index++;
	}
	file->print_args[index] = 0;
}

int	ft_directcmp(char *line, char *cmp)
{
	int	index;

	index = 0;
	if (!line || !cmp)
		return (127);
	while (line[index] == cmp[index])
	{
		if (!line[index + 1])
			return (0);
		index++;
	}
	return (1);
}
