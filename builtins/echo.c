/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/13 17:59:23 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char *line)
{
	if (ft_strncmp(line, "echo ", 5) && ft_strlen(line) >= 5)
	{
		printf("%s: command not found\n", line);
		return (1);
	}
	if (ft_strlen(line) >= 7 && !ft_strncmp(line, "echo -n", 7))
	{
		if (ft_strlen(line) >= 8 && line[7] != ' ')
		{
			printer(line, 5);
			printf("\n");
		}
		else if (ft_strlen(line) == 7 || (ft_strlen(line) == 8 && line[7] == ' '))
			return (1);
		else
			printer(line, 8);
	}
	else
	{
		printer(line, 5);
		printf("\n");
	}
	return (0);
}

void	printer(char *line, size_t pos)
{
	if (pos >= ft_strlen(line))
		return ;
	while (line[pos])
	{
		if (line[pos] == '$')
		{
			if (ft_expand_env(line, &pos) == 1)
				break ;
		}
		if (line[pos])
			printf("%c", line[pos++]);
	}
}
