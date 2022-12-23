/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/23 13:59:36 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	break_line(char *line)
{
	char	*new_line;

	new_line = adjust_line(line);
	free (line);
	to_builtins(new_line);
	free (new_line);
}

void	to_builtins(char *line)
{
	if (!ft_strncmp(line, "echo -n", 7))
		data()->exit_status = ft_echo_n(line);
	else if (!ft_strncmp(line, "echo", 4))
		data()->exit_status = ft_echo(line);
	else if (!ft_strncmp(line, "pwd", 3))
		data()->exit_status = ft_pwd(line);
	else if (!ft_strncmp(line, "cd", 2))
		data()->exit_status = ft_cd(line);
	else if (!ft_strncmp(line, "env", 3))
		data()->exit_status = print_envs(data()->env, line);
	else if (!ft_strncmp(line, "exit", 4))
		data()->exit_status = ft_exit(line);
	else if (!ft_strncmp(line, "export", 6))
		data()->exit_status = ft_export(line);
	else
	{
		printf("%s: command not found\n", line);
		data()->exit_status = 127;
	}
}
