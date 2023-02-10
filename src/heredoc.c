/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:55:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/02/10 19:29:23 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_rederror(char *line)
{
	if (!line)
	{
		printf("-bash: syntax error near unexpected token `newline'\n");
		return (data()->exit_status = 258);
	}
	else if (!ft_recmp(line, "<") || !ft_recmp(line, ">")
		|| !ft_recmp(line, ">>") || !ft_recmp(line, "<<"))
	{
		printf("-bash: syntax error near unexpected token `%s'\n", line);
		return (data()->exit_status = 258);
	}
	return (0);
}

int	check_redirect(char **line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (!ft_recmp(line[index], "<") 
			&& print_rederror(line[index + 1]))
			return (1);
		else if (!ft_recmp(line[index], "<<") 
			&& print_rederror(line[index + 1]))
			return (1);
		else if (!ft_recmp(line[index], ">") 
			&& print_rederror(line[index + 1]))
			return (1);
		else if (!ft_recmp(line[index], ">>") 
			&& print_rederror(line[index + 1]))
			return (1);
		index++;
	}
	return (0);
}

int	check_is_heredoc(char **line)
{
	int	index;
	int	flg;

	index = 0;
	flg = 0;
	while (line[index])
	{
		if (!ft_recmp(line[index], "<<") && !ft_recmp(line[index + 1], "<<"))
		{
			printf("-bash: syntax error near unexpected token `<<'\n");
			if (flg == 1)
				return (1);
			else if (flg == 0)
				return (0);
		}
		else if (!ft_recmp(line[index], "<<") && line[index + 1])
			flg = 1;
		index++;
	}
	if (flg == 1)
		return (1);
	return (0);
}

char	*remove_quotes(char *str)
{
	int		len;
	int		index;
	char	*str2;

	len = 0;
	index = 0;
	while (str[len])
		len++;
	str2 = malloc(sizeof(char) * len);
	len = 0;
	while (str[len])
	{
		if (str[len] != 39 && str[len] != 34)
		{
			str2[index] = str[len];
			index++;
		}
		len++;
	}
	str2[index] = '\0';
	free(str);
	return (str2);
}

void	fix_args(char **lista)
{
	int		index;
	char	*str;

	index = 0;
	while (lista[index])
	{
		if (!ft_recmp(lista[index], "'<'") || !ft_recmp(lista[index], "'<<'")
			||!ft_recmp(lista[index], "'>'") || !ft_recmp(lista[index], "'>>'")
			||!ft_recmp(lista[index], "\"<\"") || !ft_recmp(lista[index], "\"<<\"")
			||!ft_recmp(lista[index], "\">\"") || !ft_recmp(lista[index], "\">>\""))
		{
			str = remove_quotes(lista[index]);
			lista[index] = str;
		}
		index++;
	}
}
