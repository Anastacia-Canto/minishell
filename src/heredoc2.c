/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:51 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/10 17:20:52 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_info(t_heredoc *file, char **line, int *pd)
{
	int		check;
	char	*temp;

	check = 0;
	file->input_len = input_len(line, file);
	file->output_len = output_len(line);
	get_inputs(line, file);
	get_outputs(line, file);
	get_args(line, file);
	fix_args(file->args);
	check = check_is_heredoc(line);
	if (check)
		ft_double_less(line, file);
	check = check_redirect(line);
	if (!check && open_files(line, file))
		execute_redirection(file, pd);
	temp = get_pfile(".tmp_heredoc2024.txt");
	if (!temp)
		return ;
	if (access(temp, F_OK) == 0)
		unlink(temp);
	free_array(file->all_inputs);
	free_array(file->all_outputs);
	free_array(file->args);
	free(temp);
}

void	heredoc(char **line, int *pd)
{
	t_heredoc	file;

	file.here_flag = 0;
	get_info(&file, line, pd);
}
