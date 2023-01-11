/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:05:27 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/11 16:26:57 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	b = c;
	i = 0;
	if (!s)
		return (NULL);
	while (s && s[i] && (s[i] != b))
		i++;
	if (s[i] == b)
		return ((char *)s + i);
	else
		return (NULL);
}
