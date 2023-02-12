/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2023/02/12 19:16:18 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **line, int fd)
{
	if (array_len(line) == 1)
	{
		write(fd, "\n", 1);
		return (0);
	}
	if (!ft_strncmp(line[1], "-n", 2) && !check_n(line[1]))
		return (ft_echo_n(line, fd));
	else if (!ft_strncmp(line[1], "$?", sizeof(line[1])))
	{
		free(line[1]);
		line[1] = ft_itoa(data()->exit_status);
	}
	print_echo(line, fd, 0);
	write(fd, "\n", 1);
	return (0);
}

void	print_echo(char **line, int fd, int i)
{
	int		j;

	while (line[++i])
	{
		j = 0;
		while (line[i][j])
			write(fd, &line[i][j++], 1);
		if (i < array_len(line) - 1)
			write(fd, " ", 1);
	}
}

int	ft_echo_n(char **line, int fd)
{
	int	j;

	if (array_len(line) == 2)
		return (0);
	j = 1;
	if (!ft_strncmp(line[2], "$?", sizeof(line[1])))
	{
		free(line[2]);
		line[2] = ft_itoa(data()->exit_status);
	}
	while (!check_n(line[j]))
		j++;
	j--;
	print_echo(line, fd, j);
	return (0);
}

int	check_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (i < (int)ft_strlen(arg))
	{
		if (arg[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}
