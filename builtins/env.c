/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:17 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/16 15:35:47 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expand_env(char *line, size_t *pos)
{
	int		end;
	char	*value;
	char	*name;

	end = *pos;
	while (line[end] && !ft_whitespace(line[end]))
		end++;
	name = ft_substr(line, *pos + 1, end - *pos - 1);
	value = getenv(name);
	free (name);
	if (!value)
		return (1);
	printf("%s", value);
	*pos = end;
	return (0);
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
