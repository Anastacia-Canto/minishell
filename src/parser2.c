/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:14:34 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/03 17:23:17 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	end_heredoc(char *line, int i)
{
	if (i == (int)ft_strlen(line) - 1)
		return (0);
	if (line[i] == '>' && line[i + 1] != '>' && !ft_whitespace(line[i + 1]))
		return (1);
	else if (line[i] == '<' && line[i + 1] != '<'
		&& !ft_whitespace(line[i + 1]))
		return (1);
	return (0);
}

void	finalize_arg(char *temp, int *j, char **args, int *k)
{
	temp[*j] = '\0';
	args[*k] = ft_strdup(temp);
	if (data()->expand)
		args[*k] = check_if_env(args[*k]);
	if (!args[*k])
	{
		free(args[*k]);
		*k = *k - 1;
	}
	*k = *k + 1;
	*j = 0;
	data()->expand = 1;
}

void	copy_arg(char *line, int *i, char *temp, int *j)
{
	int	k;
	int	w;

	k = *i;
	w = *j;
	if (is_quote(line[k]) && !check_end_quote(line, &k))
	{
		ft_ignore(line, k, temp, &w);
		while (line[++k] && !is_quote(line[k]))
			temp[w++] = line[k];
		if (data()->ignore_sign)
		{
			temp[w++] = line[k];
			data()->ignore_sign = 0;
		}
		*i = k + 1;
		*j = w;
	}
	else
	{
		while (line[k] && !ft_whitespace(line[k]) && !is_quote(line[k]))
		{
			temp[w++] = line[k++];
			if (end_heredoc(line, k - 1))
				break ;
		}
		*i = k;
		*j = w;
	}
}

void	ft_ignore(char *line, int k, char *temp, int *w)
{
	int	i;

	i = k + 1;
	if (!((line[i] == '>') && line[i + 1] && (is_quote(line[i + 1])
				|| (line[i + 1] == '>'
					&& line[i + 2] && is_quote(line[i + 2])))))
		return ;

	if (!((line[i] == '<') && line[i + 1] && (is_quote(line[i + 1])
				|| (line[i + 1] == '<'
					&& line[i + 2] && is_quote(line[i + 2])))))
		return ;
	data()->ignore_sign = 1;
	temp[*w] = line[k];
	*w = *w + 1;
}
