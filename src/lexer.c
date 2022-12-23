/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/23 15:58:23 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	break_in_cmd(char *line)
{
	char	*adjusted_line;
	char	**cmds;
	int		i;

	cmds = ft_split(line, '|');
	free (line);
	i = 0;
	while (cmds[i])
	{
		adjusted_line = adjust_line(cmds[i++]);
		to_builtins(adjusted_line);
		free (adjusted_line);
	}
	free_array(cmds);
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
	else if (!ft_strncmp(line, "./", 2))
		data()->exit_status = ft_exec(line);
	else
	{
		printf("%s: command not found\n", line);
		data()->exit_status = 127;
	}
}

int	ft_exec(char *line)
{
	int		ret;
	char	*new_line;
	char	*path;
	char	**args;
	size_t	i;

	ret = 0;
	i = ft_strlen(line);
	while (line[i] != '/')
		i--;
	new_line = ft_substr(line, i + 1, ft_strlen(line) - i + 1);
	args = ft_split(new_line, ' ');
	i = 0;
	while (!(line[i] == '.' && line[i + 1] == 's' && line[i + 2] == 'h'))
		i++;
	path = ft_substr(line, 0, i + 3);
	ret = execve(path, args, data()->env);
	free (new_line);
	free (path);
	free_array(args);
	return (ret);
}
