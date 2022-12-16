/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:04:07 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/16 14:08:54 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;
	size_t	a;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= len_dst)
		return (len_src + dstsize);
	i = 0;
	while (dst[i])
		i++;
	a = 0;
	while (src[a] && (a < (dstsize - len_dst -1)))
	{
		dst[i + a] = src[a];
		a++;
	}
	dst[i + a] = '\0';
	return (len_src + len_dst);
}
