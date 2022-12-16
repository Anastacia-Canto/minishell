/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:09:46 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/16 14:04:34 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned char	*src;
	size_t			size;
	size_t			i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	size = ft_strlen(s);
	str = malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	src = (unsigned char *)s;
	i = 0;
	while ((i < len) && ((start + i) < size))
	{
		str[i] = src[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
