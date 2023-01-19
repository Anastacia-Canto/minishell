/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:55:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/19 16:27:07 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_is_heredoc(char **line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (!ft_recmp(line[index], "<<"))
			return (1);
		index++;
	}
	return (0);
}

void	get_info(t_heredoc *file, char **line, int *pd)
{
	file->input_len = input_len(line, file);
	file->output_len = output_len(line);
	get_inputs(line, file);
	get_outputs(line, file);
	get_args(line, file);
	if (check_is_heredoc(line))
		ft_double_less(line, file);
	if (open_files(line, file))
		execute_redirection(file, pd);
	free_array(file->all_inputs);
	free_array(file->all_outputs);
	free_array(file->args);
}

void	heredoc(char **line, int *pd)
{
	t_heredoc	file;

	file.here_flag = 0;
	get_info(&file, line, pd);
}
