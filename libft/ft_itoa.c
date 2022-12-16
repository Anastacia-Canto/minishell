/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:11:47 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/16 14:06:18 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_n(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len_n;
	char	*str;
	long	nb;

	nb = n;
	len_n = get_len_n(nb);
	str = malloc(sizeof(*str) * (len_n + 1));
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	else if (nb == 0)
		str[0] = '0';
	str[len_n] = '\0';
	len_n--;
	while (nb > 0)
	{
		str[len_n] = nb % 10 + 48;
		nb /= 10;
		len_n--;
	}
	return (str);
}
