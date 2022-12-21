/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:17:29 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/21 17:51:19 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_args(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (is_quote(line[i]))
			return (1);
		i++;
	}
	return (0);
}

void	args_parser(char *line)
{
	int		i;

	if (!check_args(line))
		split_args(line);
	else
	{
		i = 0;
		while (line[i])
		{
			if (is_quote(line[i]))
				get_quoted_arg(line, &i);
			else if (ft_whitespace(line[i]))
			{
				while (line[i] && ft_whitespace(line[i]))
					i++;
				if (line[i])
					printf(" ");
			}
			else
				get_arg(line, &i);
		}
	}
}

void	split_args(char *line)
{
	int		i;
	int		len;
	char	**args;

	args = ft_split(line, ' ');
	len = array_len(args);
	i = 0;
	while (i < len -1)
	{
		printer(args[i++]);
		printf(" ");
	}
	printer(args[i]);
	free_array(args);
}

void	get_quoted_arg(char *line, int *pos)
{
	int		i;
	char	*arg;

	i = *pos + 1;
	while (line[i] && line[i] != line[*pos])
		i++;
	if (i == *pos + 1)
	{
		*pos = i + 1;
		return ;
	}
	if (line[*pos] == '\'')
		data()->expand = 0;
	if (line[i])
		arg = ft_substr(line, *pos + 1, i - *pos - 1);
	if (arg)
	{
		printer(arg);
		free (arg);
	}
	*pos = i + 1;
	data()->expand = 1;
}

void	get_arg(char *line, int *pos)
{
	int		i;
	char	*arg;

	i = *pos;
	while (line[i] && !ft_whitespace(line[i]) && !is_quote(line[i]))
		i++;
	arg = ft_substr(line, *pos, i - *pos);
	if (arg)
	{
		printer(arg);
		free (arg);
	}
	*pos = i;
}
