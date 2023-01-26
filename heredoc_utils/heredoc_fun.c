/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:22:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/26 12:07:28 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_here_str(char **line, t_heredoc *file)
{
	int	index;
	int	len;

	index = -1;
	len = 0;
	while (line[++index])
		if (!ft_recmp(line[index], "<<"))
			len++;
	file->here_str = malloc(sizeof(char *) * (len + 1));
	if (!file->here_str)
		return ;
	index = -1;
	len = 0;
	while (line[++index])
		if (!ft_recmp(line[index], "<<"))
			if (line[index + 1])
				file->here_str[len++] = ft_strdup(line[index + 1]);
	file->here_str[len] = 0;
}

int	check_here_args(t_heredoc *file)
{
	if (!ft_recmp(file->here_str[file->index], file->line2))
	{
		data()->stop_wr = 1;
		file->index++;
	}
	if (!file->here_str[file->index])
		return (0);
	return (1);
}

void	save_heredoc(char *line, int fd)
{
	int	index;

	index = 0;
	if (!line)
		return ;
	while (line[index])
	{
		write(fd, &line[index], 1);
		index++;
	}
	write(fd, "\n", 1);
}

char	*get_pfile(char *line)
{
	char	*path;
	char	*temp;
	char	*aux;

	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		return (NULL);
	temp = ft_strdup(path);
	aux = ft_strjoin(temp, "/");
	free (temp);
	temp = ft_strjoin(aux, line);
	free (aux);
	free(path);
	return (temp);
}

void	ft_double_less(char **line, t_heredoc *file)
{
	// char	*temp;

	get_here_str(line, file);
	file->index = 0;
	data()->stop_wr = 0;
	file->H_file = open(".tmp_heredoc2024.txt", O_CREAT | O_RDWR, S_IRWXU);
	file->line2 = readline(">");
	if (file->line2 != NULL)
	{
		while (check_here_args(file))
		{
			if (!data()->stop_wr)
				save_heredoc(file->line2, file->H_file);
			free(file->line2);
			file->line2 = readline(">");
			if (file->line2 == NULL)
				break ;
		}
	}
	free(file->line2);
	close(file->H_file);
	free_array(file->here_str);
}
