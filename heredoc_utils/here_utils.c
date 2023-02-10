/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:11:09 by sde-mull          #+#    #+#             */
/*   Updated: 2023/02/10 17:34:17 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_recmp(char *line, char *cmp)
{
	int	index;

	index = 0;
	if (!line || !cmp)
		return (127);
	while (line[index] == cmp[index])
	{
		if (!line[index + 1] && !cmp[index + 1])
			return (0);
		index++;
	}
	return (1);
}

int	input_len(char **line, t_heredoc *file)
{
	int	index;
	int	len;

	index = -1;
	len = 0;
	file->arg_len = 0;
	while (line[++index])
	{
		if (!ft_recmp(line[index], "<") || !ft_recmp(line[index], "<<"))
		{
			if (line[index + 1])
			{
				len++;
				index++;
			}
		}
		else if (!ft_recmp(line[index], ">") || !ft_recmp(line[index], ">>"))
		{
			if (line[index + 1])
				index++;
		}
		else
			file->arg_len++;
	}
	return (len);
}

int	output_len(char **line)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (line[index])
	{
		if (!ft_recmp(line[index], ">") || !ft_recmp(line[index], ">>"))
			if (line[index + 1])
					len++;
		index++;
	}
	return (len);
}

void	get_inputs(char **line, t_heredoc *file)
{
	char	*aux;

	file->index = 0;
	file->i_input = 0;
	file->all_inputs = malloc(sizeof(char *) * (file->input_len + 1));
	if (!file->all_inputs)
		return ;
	while (line[++file->index])
	{
		if (!ft_recmp(line[file->index], "<")
			|| !ft_recmp(line[file->index], "<<"))
		{
			if (line[file->index + 1])
			{
				aux = ft_strdup(line[file->index + 1]);
				file->all_inputs[file->i_input++] = aux;
				file->index++;
			}
		}
	}
	file->all_inputs[file->i_input] = 0;
}

void	get_outputs(char **line, t_heredoc *file)
{
	char	*aux;

	file->index = 0;
	file->i_output = 0;
	file->all_outputs = malloc(sizeof(char *) * (file->output_len + 1));
	if (!file->all_outputs)
		return ;
	while (line[file->index])
	{
		if (!ft_recmp(line[file->index], ">")
			|| !ft_recmp(line[file->index], ">>"))
		{
			if (line[file->index + 1])
			{
				aux = ft_strdup(line[file->index + 1]);
				file->all_outputs[file->i_output++] = aux;
			}
		}
		file->index++;
	}
	file->all_outputs[file->i_output] = 0;
}
