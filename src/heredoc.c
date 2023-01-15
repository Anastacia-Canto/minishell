/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:55:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/15 16:30:32 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_info(t_heredoc *file, char **line, int *pd)
{
	file->input_len = input_len(line, file);
	file->output_len = output_len(line);
	get_inputs(line, file);
	get_outputs(line, file);
	get_args(line, file);
	if(open_files(line, file))
		execute_redirection(file, pd);
	free_array(file->all_inputs);
	free_array(file->all_outputs);
	free_array(file->args);
}

void	heredoc(char **line, int *pd)
{
	t_heredoc file;
	
	get_info(&file, line, pd);
}
