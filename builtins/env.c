/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:17 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/29 16:53:20 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expand_env(char *line, size_t **pos)
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
	print_env_value(value);
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
