/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:22:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/13 00:06:56 by sde-mull         ###   ########.fr       */
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

void	ft_greater(char **line, int fd, int *pd)
{
	t_heredoc 	file;
	int			index;
	char		*temp;
	int			tmpout;

	index = 0;
	tmpout = dup(1);
	while (ft_strcmp(line[index++], ">"));
	get_args(line, index, &file);
	temp = get_pfile(line[index]);
	if (!temp)
		return ;
	if (access(temp, F_OK) == 0)
		unlink(temp);
	file.fd1 = open(line[index], O_RDWR | O_CREAT, 777);
	dup2(file.fd1, 1);
	free(temp);
	to_builtins(file.print_args , 1, pd);
	dup2(tmpout, 1);
	close(file.fd1);
}
