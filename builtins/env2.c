/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:29:32 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/27 17:16:29 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_if_env(char *name)
{
	char	*new_name;
	int		i;

	if (!ft_strchr(name, '$'))
		return (name);
	i = 0;
	while (name[i] != '$' && !ft_whitespace(name[i]))
		i++;
	if (name[i] != '$')
		return (name);
	new_name = expand_cli_env(name);
	free (name);
	return (new_name);
}

char	*expand_cli_env(char *name)
{
	char	*new_name;
	int		start;
	int		end;
	char	*value;
	char	*key;

	start = 0;
	while (name[start] && name[start] != '$')
		start++;
	end = start;
	while (name[end] && !ft_whitespace(name[end]))
		end++;
	key = ft_substr(name, start + 1, end - start - 1);
	value = getenv(key);
	if (!value)
		value = get_var(key);
	free (key);
	if (!value)
		return (ft_strdup(name));
	new_name = concat_str(name, value);
	return (new_name);
}

char	*concat_str(char *name, char *value)
{
	int		i;
	int		j;
	int		k;
	int		flag;
	char	*new_name;

	new_name = malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(value) + 1));
	if (!new_name)
		return (NULL);
	flag = 0;
	i = 0;
	j = 0;
	while (name[i])
	{
		if (name[i] == '$' && !flag)
		{
			flag = 1;
			while (name[i] && !ft_whitespace(name[i]))
				i++;
			k = 0;
			while (value[k])
			{
				if (value[k] == '=')
					k++;
				new_name[j++] = value[k++];
			}
		}
		else
			new_name[j++] = name[i++];
	}
	new_name[j] = '\0';
	return (new_name);
}
