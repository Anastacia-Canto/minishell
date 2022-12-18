/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:26:37 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/18 00:35:11 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (ptr && size == 0)
		free (ptr);
	new = malloc(sizeof(ptr) * size);
	if (!ptr)
		return (new);
	if (!new)
		return (ptr);
	if (size > ft_strlen(ptr))
		size = ft_strlen(ptr);
	new = ft_memcpy(new, ptr, size);
	return (new);
}
