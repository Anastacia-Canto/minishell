/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:17:29 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/06 02:29:24 by sde-mull         ###   ########.fr       */
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

void	args_parser(char *line, int fd)
{
	int		i;

	if (!check_args(line))
		split_args(line, fd);
	else
	{
		i = 0;
		while (line[i])
		{
			if (is_quote(line[i]) && !check_end_quote(line, &i))
				get_quoted_arg(line, &i, fd);
			else if (ft_whitespace(line[i]))
			{
				while (line[i] && ft_whitespace(line[i]))
					i++;
				if (line[i])
					write(fd, " ", 1);
			}
			else
				get_arg(line, &i, fd);
		}
	}
}

void	split_args(char *line, int fd)
{
	int		i;
	int		len;
	char	**args;
	int		flag;

	args = ft_split(line, ' ');
	len = array_len(args);
	i = 0;
	while (i < len -1)
	{
		flag = printer(args[i++], fd);
		if (!flag)
			write(fd, " ", 1);
	}
	printer(args[i], fd);
	free_array(args);
}

void	get_quoted_arg(char *line, int *pos, int fd)
{
	int		i;
	char	*arg;

	i = *pos + 1;
	arg = NULL;
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
		printer(arg, fd);
		free (arg);
	}
	*pos = i + 1;
	data()->expand = 1;
}

void	get_arg(char *line, int *pos, int fd)
{
	int		i;
	char	*arg;

	i = *pos;
	while (line[i] && !ft_whitespace(line[i]) && !is_quote(line[i]))
		i++;
	arg = ft_substr(line, *pos, i - *pos);
	if (arg)
	{
		printer(arg, fd);
		free (arg);
	}
	*pos = i;
}
