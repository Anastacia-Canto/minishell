/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/15 15:49:07 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	break_line(char *line)
{
	char	*new_line;

	new_line = fix_spaces(line);
	free (line);
	to_builtins(new_line);
	free (new_line);
}

void	to_builtins(char *line)
{
	if (!ft_strncmp(line, "echo", 4))
		ft_echo(line);
	else if (!ft_strncmp(line, "pwd", 3))
		ft_pwd(line);
	else if (!ft_strncmp(line, "cd", 2))
		ft_cd(line);
	else if (!ft_strncmp(line, "env", 3))
		print_envs(data()->env, line);
	else if (!ft_strncmp(line, "exit", 4))
		ft_exit(line);
}
