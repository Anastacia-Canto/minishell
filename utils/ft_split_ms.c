/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:31:53 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/02 16:46:23 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_str_ms(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (ft_whitespace(s[i]))
			i++;
		else
		{
			count++;
			while (s[i] && !ft_whitespace(s[i]))
				i++;
		}
	}
	return (count);
}

char	*get_str_ms(char const *s, int	*pos)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	while (ft_whitespace(s[*pos]))
		(*pos)++;
	i = *pos;
	while (s[i] && !ft_whitespace(s[i]))
	{
		len++;
		i++;
	}
	i = i - len;
	str = ft_substr(s, i, len);
	*pos = (*pos) + len;
	return (str);
}

char	**ft_split_ms(char const *s)
{
	char	**arr;
	int		count;
	int		i;
	int		pos;

	if (!s)
		return (NULL);
	count = count_str_ms(s);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < count)
	{
		arr[i] = get_str_ms(s, &pos);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
