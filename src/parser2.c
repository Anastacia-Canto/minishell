/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:14:34 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/10 15:58:06 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	finalize_arg(void)
{
	char	*aux;

	data()->temp[data()->p_temp] = '\0';
	data()->args_p[data()->p_args] = ft_strdup(data()->temp);
	if (data()->expand)
	{
		aux = check_if_env(data()->args_p[data()->p_args]);
		data()->args_p[data()->p_args] = aux;
	}
	if (!data()->args_p[data()->p_args]
		|| ft_strlen(data()->args_p[data()->p_args]) == 0)
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
	if (is_quote(line[*i]) && !check_end_quote(line, i))
	{
		ft_ignore(line, *i);
		while (line[++(*i)] && !is_quote(line[*i]))
			data()->temp[data()->p_temp++] = line[*i];
		if (data()->ignore_sign)
		{
			data()->temp[data()->p_temp++] = line[*i];
			data()->ignore_sign = 0;
		}
		(*i)++;
	}
	else
	{
		while (line[*i] && !ft_whitespace(line[*i]) && !is_quote(line[*i]))
		{
			if (line[*i] == '|' || line[*i] == '>' || line[*i] == '<')
				break ;
			data()->temp[data()->p_temp++] = line[(*i)++];
		}
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

int	count_cmds(char **args)
{
	int	i;
	int	cmds;

	i = -1;
	cmds = 1;
	while (args[++i])
	{
		if (!ft_strncmp(args[i], "|", sizeof(args[i])))
			cmds++;
	}
	return (cmds);
}
