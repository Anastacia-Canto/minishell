/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:17 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/27 16:29:51 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expand_env(char *line, size_t **pos)
{
	int		end;
	char	*value;
	char	*name;

	end = **pos;
	while (line[end] && (!ft_whitespace(line[end])
			&& line[end] != '\"' && line[end] != '\''))
		end++;
	name = ft_substr(line, **pos + 1, end - **pos - 1);
	value = getenv(name);
	if (!value)
		value = get_var(name);
	free (name);
	**pos = end;
	if (!value)
		return (1);
	print_env_value(value);
	return (0);
}

char	*get_var(char *name)
{
	char	*value;
	int		i;

	value = NULL;
	i = 0;
	while (data()->vars[i])
	{
		if (!ft_strncmp(name, data()->vars[i], ft_strlen(name)))
			value = ft_strchr(data()->vars[i], '=');
		i++;
	}
	return (value);
}

void	print_env_value(char *value)
{
	int	i;

	if (value[0] == '=')
	{
		i = 1;
		while (value[i])
			printf("%c", value[i++]);
	}
	else
		printf("%s", value);
}

int	print_envs(char **env, char *line)
{
	int	i;

	if (!env || !*env)
		return (1);
	if (check_cmd_name(line, "env ", 4))
		return (127);
	i = 0;
	while (env[i])
		printf("%s\n", env[i++]);
	return (0);
}
