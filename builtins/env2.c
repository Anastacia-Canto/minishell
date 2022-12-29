/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:29:32 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/29 11:38:18 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_if_env(char *name)
{
	char	*new_name;
	int		dollars;
	int		i;

	if (!ft_strchr(name, '$'))
		return (name);
	i = 0;
	dollars = 0;
	while (name[i] && !ft_whitespace(name[i]))
	{
		if (name[i] == '$')
			dollars++;
		i++;
	}
	if (!dollars)
		return (name);
	new_name = expand_cli_env(name, dollars);
	if (!new_name)
		return (name);
	free (name);
	return (new_name);
}

char	*expand_cli_env(char *name, int dollars)
{
	int		i;
	char	*new_name;

	new_name = "";
	i = 0;
	if (name[i] != '$')
	{
		while (name[i] && name[i] != '$' && !ft_whitespace(name[i]))
			i++;
		new_name = ft_substr(name, 0, i);
	}
	while (dollars > 0)
	{
		i++;
		new_name = concat_env(new_name, get_value(name, &i));
		dollars--;
	}
	new_name = concat_env(new_name, (char *)name + i);
	return (new_name);
}

char	*get_value(char *name, int *pos)
{
	int		end;
	char	*value;
	char	*key;

	end = *pos;
	while (name[end] && name[end] != '$' && !ft_whitespace(name[end]))
		end++;
	key = ft_substr(name, *pos, end - *pos);
	value = getenv(key);
	if (!value)
	{
		value = get_var(key);
		value++;
	}
	*pos = end;
	free (key);
	return (value);
}

char	*concat_env(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = -1;
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	// free (s1);
	return (ret);
}
