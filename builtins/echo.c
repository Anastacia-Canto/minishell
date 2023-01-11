/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/11 12:29:52 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char *line, int fd)
{
	char	*str;

	if (check_cmd_name(line, "echo ", 5))
		return (127);
	str = ft_substr(line, 5, ft_strlen(line) - 5);
	if (!str)
	{
		write(fd, "\n", 1);
		return (0);
	}
	args_parser(str, fd);
	write(fd, "\n", 1);
	free (str);
	return (0);
}

int	ft_echo_n(char *line, int fd)
{
	char	*str;
	size_t	i;

	if (check_cmd_name(line, "echo -n ", 8))
		return (127);
	i = 8;
	while (line[i] && ft_whitespace(line[i]))
		i++;
	str = ft_substr(line, i, ft_strlen(line) - i + 1);
	if (!str)
		return (0);
	args_parser(str, fd);
	free (str);
	return (0);
}

int	printer(char *line, int fd)
{
	size_t	pos;

	pos = 0;
	while (pos < ft_strlen(line) && line[pos])
	{
		if (line[pos] == '$')
		{
			if (!echo_dollar(line, &pos, fd))
				write(fd, &line[pos++], 1);
		}
		else if (line[pos])
			write(fd, &line[pos++], 1);
	}
	return (0);
}

int	echo_dollar(char *line, size_t *pos, int fd)
{
	if (line[*pos + 1] == '?')
	{
		ft_putnbr_fd(data()->exit_status, fd);
		*pos += 2;
	}
	else if (data()->expand)
		return (ft_expand_env(line, &pos, fd));
	return (0);
}

int	is_quote(char c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}
