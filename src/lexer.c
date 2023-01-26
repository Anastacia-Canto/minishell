/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/26 11:42:56 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	to_builtins(char **line, int fd, int *pd)
{
	int	exit;

	if (!ft_strncmp(line[0], "echo", sizeof(line[0])))
		exit = ft_echo(line, fd);
	else if (!ft_strncmp(line[0], "pwd", sizeof(line[0])))
		exit = ft_pwd(fd);
	else if (!ft_strncmp(line[0], "cd", sizeof(line[0])))
		exit = ft_cd(line);
	else if (!ft_strncmp(line[0], "env", sizeof(line[0])))
		exit = print_envs(data()->env, line, fd);
	else if (!ft_strncmp(line[0], "exit", sizeof(line[0])))
		exit = ft_exit(line, fd, pd);
	else if (!ft_strncmp(line[0], "export", sizeof(line[0])))
		exit = ft_export(line, fd);
	else if (!ft_strncmp(line[0], "unset", sizeof(line[0])))
		exit = ft_unset(line);
	else
		exit = treat_others(line, fd);
	data()->exit_status = exit;
}

int	treat_others(char **line, int fd)
{
	int		ret;

	ret = 0;
	if (!check_line(line[0]))
		return (add_var(line[0]));
	data()->sig = 1;
	ret = ft_exec(line, fd);
	data()->sig = 0;
	return (ret);
}
