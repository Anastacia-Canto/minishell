/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:22:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/13 09:20:11 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_greater(char **line, int *pd)
{
	t_heredoc	file;

	file.index = 0;
	file.tmpout = dup(1);
	while (ft_directcmp(line[file.index], ">"))
		file.index++;
	get_args(line, ++file.index, &file);
	file.fd1 = open(line[file.index], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	dup2(file.fd1, 1);
	to_builtins(file.print_args, 1, pd);
	dup2(file.tmpout, 1);
	close(file.fd1);
	free_array(file.print_args);
}

void	ft_double_greater(char **line, int *pd)
{
	t_heredoc	file;

	file.index = 0;
	file.tmpout = dup(1);
	while (ft_directcmp(line[file.index], ">>"))
		file.index++;
	get_args(line, ++file.index, &file);
	file.fd1 = open(line[file.index], O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
	if (file.fd1 < 0)
		return ;
	dup2(file.fd1, 1);
	to_builtins(file.print_args, 1, pd);
	dup2(file.tmpout, 1);
	close(file.fd1);
	free_array(file.print_args);
}

void	ft_less(char **line, int *pd)
{
	t_heredoc	file;

	file.index = 0;
	file.tmpin = dup(0);
	while (ft_directcmp(line[file.index], "<"))
		file.index++;
	get_args(line, ++file.index, &file);
	file.fd1 = open(line[file.index], O_RDONLY, 0777);
	if (file.fd1 < 0)
	{
		printf("%s: No such file or directory\n", line[file.index]);
		return ;
	}
	dup2(file.fd1, 0);
	to_builtins(file.print_args, 1, pd);
	dup2(file.tmpin, 0);
	close(file.fd1);
	free_array(file.print_args);
}

void	ft_double_less(char **line, int *pd)
{
	(void)line;
	(void)pd;
	// t_heredoc	file;
}
