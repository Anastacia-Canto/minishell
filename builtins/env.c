/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:17 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/06 02:34:38 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expand_env(char *line, size_t **pos, int fd)
{
	int		end;
	char	*value;
	char	*name;

	end = **pos + 1;
	while (line[end] && (!ft_whitespace(line[end])
			&& line[end] != '\"' && line[end] != '\''
			&& line[end] != '$'))
		end++;
	name = ft_substr(line, **pos + 1, end - **pos - 1);
	value = get_var(name, 0);
	if (!value)
		value = get_var(name, 1);
	free (name);
	**pos = end;
	if (!value)
		return (1);
	print_env_value(value, fd);
	return (1);
}

char	*get_var(char *name, int id)
{
	char	*value;
	char	*ref_key;
	char	**list;
	int		i;
	int		j;

	list = data()->env;
	if (id == 1)
		list = data()->vars;
	value = NULL;
	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j] && list[i][j] != '=')
			j++;
		ref_key = ft_substr(list[i], 0, j);
		if (ft_strlen(name) != ft_strlen(ref_key))
		{
			free (ref_key);
			i++;
			continue ;
		}
		if (!ft_strncmp(name, ref_key, ft_strlen(ref_key)))
		{
			value = ft_strchr(list[i], '=');
			value++;
		}
		i++;
		free (ref_key);
	}
	return (value);
}

void	print_env_value(char *value, int fd)
{
	int		i;
	size_t	len;

	if (value[0] == '=')
	{
		i = 1;
		while (value[i])
			write(fd, &value[i++], 1);
	}
	else
	{
		len = ft_strlen(value);
		write(fd, value, len);
	}
}

int	print_envs(char **env, char *line, int fd)
{
	int		i;
	size_t	len;

	if (!env || !*env)
		return (1);
	if (check_cmd_name(line, "env ", 4))
		return (127);
	i = 0;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		write(fd, env[i++], len);
		write(fd, "\n", 1);
	}
	return (0);
}
