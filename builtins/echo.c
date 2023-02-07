/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2023/02/07 16:59:39 by sde-mull         ###   ########.fr       */
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

	// check_special_sign(line);
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
	if (!ft_strncmp(line[2], "$?", sizeof(line[1])))
	{
		free(line[2]);
		line[2] = ft_itoa(data()->exit_status);
	}
	print_echo(line, fd, 1);
	return (0);
}

int	check_n(char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	check_special_sign(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strncmp(line[i], "\'>\'", sizeof(line[i]))
			|| !ft_strncmp(line[i], "\">\"", sizeof(line[i])))
			{
				free(line[i]);
				line[i] = ft_strdup(">");
			}
		else if (!ft_strncmp(line[i], "\'>>\'", sizeof(line[i]))
			|| !ft_strncmp(line[i], "\">>\"", sizeof(line[i])))
			{
				free(line[i]);
				line[i] = ft_strdup(">>");
			}
		else if (!ft_strncmp(line[i], "\'<\'", sizeof(line[i]))
			|| !ft_strncmp(line[i], "\"<\"", sizeof(line[i])))
			{
				free(line[i]);
				line[i] = ft_strdup("<");
			}
		else if (!ft_strncmp(line[i], "\'<<\'", sizeof(line[i]))
			|| !ft_strncmp(line[i], "\"<<\"", sizeof(line[i])))
			{
				free(line[i]);
				line[i] = ft_strdup("<<");
			}
		i++;
	}
}
