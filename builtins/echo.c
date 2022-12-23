/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/23 14:14:54 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char *line)
{
	char	*str;

	if (check_cmd_name(line, "echo ", 5))
		return (127);
	str = ft_substr(line, 5, ft_strlen(line) - 4);
	if (!str)
	{
		printf("\n");
		return (0);
	}
	args_parser(str);
	printf("\n");
	free (str);
	return (0);
}

int	ft_echo_n(char *line)
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
	args_parser(str);
	free (str);
	return (0);
}

void	printer(char *line)
{
	size_t	pos;

	pos = 0;
	while (line[pos])
	{
		if (line[pos] == '$')
			echo_dollar(line, &pos);
		if (line[pos])
			printf("%c", line[pos++]);
	}
}

void	echo_dollar(char *line, size_t *pos)
{
	if (line[*pos + 1] == '?')
	{
		printf("%d", data()->exit_status);
		*pos += 2;
		return ;
	}
	else if (data()->expand)
		ft_expand_env(line, &pos);
}

int	is_quote(char c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}
