/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:11:09 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/13 00:11:29 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pfile(char *line)
{
	char 		*path;
	char		*temp;

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
	int index;

	index = 0;
	file->print_args = malloc(sizeof(char *) * len);
	while (index < len - 1)
	{
		file->print_args[index] = line[index];
		index++;
	}
	file->print_args[index] = 0;
}