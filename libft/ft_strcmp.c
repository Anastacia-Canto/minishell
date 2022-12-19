/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:05:40 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/19 18:06:11 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str, char *str2)
{
	int	index;

	index = 0;
	if (!str || !str2)
		return (0);
	while (str[index] && str2[index])
	{
		if (str[index] != str2[index])
			return (1);
		index++;
	}
	return (0);
}
