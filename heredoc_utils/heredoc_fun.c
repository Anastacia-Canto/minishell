/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:22:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/14 05:18:03 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_args_len(t_heredoc *file, char **line, char *str)
{
	file->index = 0;

	file->direction_len = 0;
	file->args_len = 0;
	while (line[file->index])
	{
		if (!ft_directcmp(line[file->index], str) && line[file->index])
			file->direction_len += 1;
		else
			file->args_len += 1;
		file->index++;
	}
	file->args_len -= file->direction_len;
}

void	ft_greater(char **line, int *pd)
{
	t_heredoc	file;

	data()->break_flg = 1;
	file.tmpout = dup(1);
	divide_args(line, &file, ">");
	file.index = 0;
	while (file.files[file.index + 1])
		open(file.files[file.index++], O_RDWR | O_CREAT, S_IRWXU);
	file.fd1 = open(file.files[file.index], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	dup2(file.fd1, 1);
	to_builtins(file.print_args, 1, pd);
	dup2(file.tmpout, 1);
	close(file.fd1);
	free_array(file.print_args);
	free_array(file.files);
}

void	ft_double_greater(char **line, int *pd)
{
	t_heredoc	file;

	data()->break_flg = 1;
	file.tmpout = dup(1);
	divide_args(line, &file, ">>");
	file.index = 0;
	while (file.files[file.index + 1])
		open(file.files[file.index++], O_RDWR | O_CREAT, S_IRWXU);
	file.fd1 = open(file.files[file.index], O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
	if (file.fd1 < 0)
		return ;
	dup2(file.fd1, 1);
	to_builtins(file.print_args, 1, pd);
	dup2(file.tmpout, 1);
	close(file.fd1);
	free_array(file.print_args);
	free_array(file.files);
}

void	ft_less(char **line, int *pd)
{
	t_heredoc	file;
;
	file.tmpin = dup(0);
	data()->break_flg = 1;
	divide_args(line, &file, "<");
	file.index = 0;
	while (file.files[file.index + 1])
		file.index++;
	file.fd1 = open(file.files[file.index], O_RDONLY, 0777);
	if (file.fd1 < 0)
	{
		printf("%s: No such file or directory\n", file.files[file.index]);
		return ;
	}
	dup2(file.fd1, 0);
	to_builtins(file.print_args, 1, pd);
	dup2(file.tmpin, 0);
	close(file.fd1);
	free_array(file.print_args);
	free_array(file.files);
}

int		check_here_args(t_heredoc *file)
{
	if (!ft_directcmp(file->files[file->index], file->line2))
	{
		data()->stop_wr = 1;
		file->index++;
	}
	if (!file->files[file->index])
		return (0);
	return (1);
}

void	ft_double_less(char **line, int *pd)
{
	t_heredoc	file;
	char		*temp;

	data()->break_flg = 1;
	file.tmpin = dup(0);
	divide_args(line, &file, "<<");
	file.fd1 = open(".heredoc.txt", O_CREAT | O_RDWR, 0777);
	file.line2 = readline(">");
	file.index = 0;
	while (check_here_args(&file))
	{
		if (!data()->stop_wr)
			save_heredoc(file.line2, file.fd1);
		free(file.line2);
		file.line2 = readline(">");
	}
	free(file.line2);
	close(file.fd1);
	file.fd1 = open(".heredoc.txt", O_CREAT | O_RDWR, 0777);
	dup2(file.fd1, 0);
	to_builtins(file.print_args, 1, pd);
	dup2(file.tmpin, 0);
	temp = get_pfile(".heredoc.txt");
	if (!temp)
		return ;
	if (access(temp, F_OK) == 0)
		unlink(temp);
	close(file.fd1);
	free_array(file.print_args);
	free_array(file.files);
	data()->stop_wr = 0;
}
