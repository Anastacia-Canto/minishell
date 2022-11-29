/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:05:27 by anastacia         #+#    #+#             */
/*   Updated: 2022/08/20 05:05:32 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	b = c;
	i = 0;
	while (s && s[i] && (s[i] != b))
		i++;
	if (s[i] == b)
		return ((char *)s + i);
	else
		return (NULL);
}