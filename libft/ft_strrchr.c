/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:05:55 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/16 14:04:50 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	b;

	b = c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == b)
			return ((char *)s + len);
		len--;
	}
	return (0);
}
