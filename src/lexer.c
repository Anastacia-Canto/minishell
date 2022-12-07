/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/07 12:24:54 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	break_line(char *line)
{
	char	*new_line;

	new_line = fix_spaces(line);
	to_builtins(new_line);
	free (new_line);
}

void	to_builtins(char *line)
{
	if (!line)
		return ;
	if (!ft_strncmp(line, "echo", 4))
		ft_echo(line);
	else if (!ft_strncmp(line, "exit", 4))
		ft_exit(line);
}



