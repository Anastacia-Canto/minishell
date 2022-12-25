/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/25 19:34:46 by sde-mull         ###   ########.fr       */
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
	else if (!ft_strncmp(line, "./", 2) || !ft_strncmp(line, "bash", 4))
		data()->exit_status = ft_exec(line);
	else if (check_value_list(line, data()->vars) != 1 && !check_line(line))
		data()->exit_status = change_or_add(line, 1, &data()->vars);
	else
	{
		printf("%s: command not found\n", line);
		data()->exit_status = 127;
	}
}

int	ft_exec(char *line)
{
	int	i;
	int	ret;
	char	*new_line;

	ret = 0;
	i = 0;
	if (!ft_strncmp(line, "./", 2) || !ft_strncmp(line, "bash ./", 7))
	{
		while (line[i] && line[i] != '/')
			i++;
	}
	else if (!ft_strncmp(line, "bash", 4))
	{
		while (line[i] && !ft_whitespace(line[i]))
			i++;
	}
	new_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	ret = exec_progm(new_line);
	free (new_line);
	return (ret);
}

int	exec_progm(char *line)
{
	int		ret;
	char	*new_line;
	char	*path;
	char	**args;
	int		i;

	ret = 0;
	i = ft_strlen(line);
	while (i >= 0 && line[i] != '/')
		i--;
	new_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	args = ft_split(new_line, ' ');
	i = 0;
	while (line[i] && !ft_whitespace(line[i]))
		i++;
	path = ft_substr(line, 0, i);
	ret = execve(path, args, data()->env);
	free (new_line);
	free (path);
	free_array(args);
	return (ret);
}
