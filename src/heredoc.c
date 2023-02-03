/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:55:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/02/03 17:24:15 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirect(char **line)
{
	int index;

	index = 0;
	while (line[index])
	{
		if (!ft_recmp(line[index], "<") && !line[index + 1])
			return (printf("-bash: syntax error near unexpected token `newline'\n"));
		else if (!ft_recmp(line[index], "<<") && !line[index + 1])
			return (printf("-bash: syntax error near unexpected token `newline'\n"));
		else if (!ft_recmp(line[index], ">") && !line[index + 1])
			return (printf("-bash: syntax error near unexpected token `newline'\n"));
		else if (!ft_recmp(line[index], ">>") && !line[index + 1])
			return (printf("-bash: syntax error near unexpected token `newline'\n"));
		index++;
	}
	return (0);
}

int	check_is_heredoc(char **line)
{
	int	index;
	int flg;

	index = 0;
	flg = 0;
	while (line[index])
	{
		if (!ft_recmp(line[index], "<<") && !ft_recmp(line[index + 1], "<<"))
		{
			printf("-bash: syntax error near unexpected token `<<'\n");
			if (flg == 1)
				return (1);
			else if (flg == 0)
				return (0);
		}
		else if (!ft_recmp(line[index], "<<") && line[index + 1])
			flg = 1;
		index++;
	}
	if (flg == 1)
		return (1);
	return (0);
}

void	get_info(t_heredoc *file, char **line, int *pd)
{
	int check;
	char *temp;

	check = 0;
	file->input_len = input_len(line, file);
	file->output_len = output_len(line);
	get_inputs(line, file);
	get_outputs(line, file);
	get_args(line, file);
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
