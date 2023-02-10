/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:14:34 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/10 11:38:21 by anastacia        ###   ########.fr       */
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

void	finalize_arg(void)
{
	data()->temp[data()->p_temp] = '\0';
	data()->args_p[data()->p_args] = ft_strdup(data()->temp);
	if (data()->expand)
		data()->args_p[data()->p_args] = check_if_env(data()->args_p[data()->p_args]);
	if (!data()->args_p[data()->p_args])
	{
		free(data()->args_p[data()->p_args]);
		data()->p_args--;
	}
	data()->p_args++;
	data()->p_temp = 0;
	data()->expand = 1;
}

void	copy_arg(char *line, int *i)
{
	int	k;

	k = *i;
	if (is_quote(line[k]) && !check_end_quote(line, &k))
	{
		ft_ignore(line, k);
		while (line[++k] && !is_quote(line[k]))
			data()->temp[data()->p_temp++] = line[k];
		if (data()->ignore_sign)
		{
			data()->temp[data()->p_temp++] = line[k];
			data()->ignore_sign = 0;
		}
		*i = k + 1;
	}
	else
	{
		while (line[k] && !ft_whitespace(line[k]) && !is_quote(line[k]))
		{
			if (line[k] == '|')
				break ;
			data()->temp[data()->p_temp++] = line[k++];
			if (end_heredoc(line, k - 1))
				break ;
		}
		*i = k;
	}
}

void	ft_ignore(char *line, int k)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	i = k + 1;
	if (((line[i] == '>') && i + 1 < len && (is_quote(line[i + 1])
				|| (line[i + 1] == '>'
					&& i + 2 < len && is_quote(line[i + 2])))))
	{
		data()->ignore_sign = 1;
		data()->temp[data()->p_temp] = line[k];
		data()->p_temp++;
	}
	else if (((line[i] == '<') && i + 1 < len && (is_quote(line[i + 1])
				|| (line[i + 1] == '<'
					&& i + 2 < len && is_quote(line[i + 2])))))
	{
		data()->ignore_sign = 1;
		data()->temp[data()->p_temp] = line[k];
		data()->p_temp++;
	}
}
