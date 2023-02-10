/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:51 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/10 20:03:46 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_here(t_heredoc *file)
{
	char	*temp;

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

void	get_info(t_heredoc *file, char **line, int *pd)
{
	int	check;
	int	check2;

	check = 0;
	file->i = 0;
	file->o = 0;
	file->in = 0;
	file->out = 1;
	file->input_len = input_len(line, file);
	file->output_len = output_len(line);
	get_inputs(line, file);
	get_outputs(line, file);
	get_args(line, file);
	fix_args(file->args);
	check = check_is_heredoc(line);
	check2 = check_redirect(line);
	if (check && !check2)
		ft_double_less(line, file);
	if (!check2 && open_files(line, file))
		execute_redirection(file, pd);
	free_here(file);
}

void	heredoc(char **line, int *pd)
{
	t_heredoc	file;

	file.here_flag = 0;
	get_info(&file, line, pd);
}
