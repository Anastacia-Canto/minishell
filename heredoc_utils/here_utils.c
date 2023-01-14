/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:11:09 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/14 05:27:35 by sde-mull         ###   ########.fr       */
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

void	get_args(char **line, t_heredoc *file, char *str)
{
	file->index = 0;
	file->iargs = 0;
	file->idir = 0;
	file->files = malloc(sizeof(char *) * (file->direction_len + 1));
	file->print_args = malloc(sizeof(char *) * (file->args_len + 1));
	while (line[file->index])
	{
		if (!ft_directcmp(line[file->index], str))
		{
			if (!line[file->index++])
				break ;
			file->files[file->idir++] = ft_strdup(line[file->index]);
		}
		else
			file->print_args[file->iargs++] = ft_strdup(line[file->index]);
		file->index++;
	}
	file->files[file->idir] = 0;
	file->print_args[file->iargs] = 0;
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

void	save_heredoc(char *line, int fd)
{
	int index;

	index = 0;
	while (line[index])
	{
		write(fd, &line[index], 1);
		index++;
	}
	write(fd, "\n", 1);
}

void	divide_args(char **line, t_heredoc *file, char *str)
 {
	get_args_len(file, line, str);
	get_args(line, file, str);
 }