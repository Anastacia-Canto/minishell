/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:11:14 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/11 08:58:46 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	*get_str(char const *s, int	*pos, char c)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	while (s[*pos] == c)
		(*pos)++;
	i = *pos;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	i = i - len;
	str = ft_substr(s, i, len);
	*pos = (*pos) + len;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;
	int		pos;

	if (!s)
		return (NULL);
	count = count_str(s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < count)
	{
		arr[i] = get_str(s, &pos, c);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
