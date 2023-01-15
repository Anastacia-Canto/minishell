/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:22:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/15 04:32:58 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	check_here_args(t_heredoc *file)
// {
// 	if (!ft_directcmp(file->files[file->index], file->line2))
// 	{
// 		data()->stop_wr = 1;
// 		file->index++;
// 	}
// 	if (!file->files[file->index])
// 		return (0);
// 	return (1);
// }

// char	*get_pfile(char *line)
// {
// 	char	*path;
// 	char	*temp;

// 	path = NULL;
// 	path = getcwd(path, 0);
// 	if (!path)
// 		return (NULL);
// 	temp = ft_strdup(path);
// 	temp = ft_strjoin(temp, "/");
// 	temp = ft_strjoin(temp, line);
// 	free(path);
// 	return (temp);
// }

// void	ft_double_less(char **line, int *pd, t_heredoc *file)
// {
// 	int temp;

// 	file->H_file = open(".tmp_heredoc2024.txt", O_CREAT | O_RDWR, 0777);
// 	file->line2 = readline(">");
// 	while (check_here_args(&file))
// 	{
// 		if (!data()->stop_wr)
// 			save_heredoc(file->line2, file->H_file);
// 		free(file->line2);
// 		file->line2 = readline(">");
// 	}
// 	free(file->line2);
// 	to_builtins(file->args, 1, pd);
// 	temp = get_pfile(".heredoc.txt");
// 	if (!temp)
// 		return ;
// 	if (access(temp, F_OK) == 0)
// 		unlink(temp);
// 	data()->stop_wr = 0;
// }