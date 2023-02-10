/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:17:46 by sde-mull          #+#    #+#             */
/*   Updated: 2023/02/10 18:56:59 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_args(char **line, t_heredoc *file)
{
	file->index = -1;
	file->i_args = 0;
	file->args = malloc(sizeof(char *) * (file->arg_len + 1));
	if (!file->args)
		return ;
	while (line[++file->index])
	{
		if (!ft_recmp(line[file->index], "<")
			|| !ft_recmp(line[file->index], "<<"))
		{
			if (line[file->index + 1])
				file->index++;
		}
		else if (!ft_recmp(line[file->index], ">")
			|| !ft_recmp(line[file->index], ">>"))
		{
			if (line[file->index + 1])
				file->index++;
		}
		else
			file->args[file->i_args++] = ft_strdup(line[file->index]);
	}
	file->args[file->i_args] = 0;
}


int	open_inputs(t_heredoc *file, char **line)
{
	if (file->in > 2)
		close(file->in);
	if (!ft_recmp(line[file->index - 1], "<"))
	{
		file->in = open(file->all_inputs[file->i], O_RDONLY, 0777);
		if (file->in < 0)
		{
			printf("%s: No such file or directory\n", file->all_inputs[file->i]);
			return (1);
		}
	}
	else if (!ft_recmp(line[file->index - 1], "<<"))
		file->in = open(".tmp_heredoc2024.txt", O_CREAT | O_RDWR, 0777);
	return (0);
}

void	open_outputs(t_heredoc *file, char **line)
{
	if (file->out > 2)
		close(file->out);
	if (!ft_recmp(line[file->index - 1], ">"))
		file->out = open(file->all_outputs[file->o], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	else if (!ft_recmp(line[file->index - 1], ">>"))
		file->out = open(file->all_outputs[file->o], O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
}

int	open_files(char **line, t_heredoc *file)
{
	file->index = -1;
	while (line[++file->index])
	{
		if (line[file->index][0] == 0)
		{
			printf("-bash: ambiguous redirect\n");
			return (0);
		}
		if (!ft_recmp(line[file->index], file->all_inputs[file->i]))
		{
			if (open_inputs(file, line))
				return (0);
			file->i++;
		}
		else if (!ft_recmp(line[file->index], file->all_outputs[file->o]))
		{
			open_outputs(file, line);
			file->o++;
		}
	}
	return (1);
}

void	execute_redirection(t_heredoc *file, int *pd)
{
	int		tmpin;
	int		tmpout;

	tmpin = dup(0);
	tmpout = dup(1);
	dup2(file->out, 1);
	dup2(file->in, 0);
	to_builtins(file->args, pd);
	close(file->in);
	close(file->out);
	dup2(tmpin, 0);
	dup2(tmpout, 1);
}
