/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/12 17:43:46 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **line, int fd)
{
	int		i;
	int		j;

	if (array_len(line) == 1)
	{
		write(fd, "\n", 1);
		return (0);
	}
	if (!ft_strncmp(line[1], "-n", sizeof(line[1])))
		return (ft_echo_n(line, fd));
	else if (!ft_strncmp(line[1], "$?", sizeof(line[1])))
	{
		free(line[1]);
		line[1] = ft_itoa(data()->exit_status);
	}
	// args_parser(str, fd);
	i = 0;
	while (line[++i])
	{
		j = 0;
		while (line[i][j])
			write(fd, &line[i][j++], 1);
		if (i < array_len(line) - 1)
			write(fd, " ", 1);
	}
	write(fd, "\n", 1);
	return (0);
}

int	ft_echo_n(char **line, int fd)
{
	int		i;
	int		j;

	if (!ft_strncmp(line[2], "$?", sizeof(line[1])))
	{
		free(line[2]);
		line[2] = ft_itoa(data()->exit_status);
	}
	i = 1;
	while (line[++i])
	{
		j = 0;
		while (line[i][j])
			write(fd, &line[i][j++], 1);
		if (i < array_len(line) - 1)
			write(fd, " ", 1);
	}
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
