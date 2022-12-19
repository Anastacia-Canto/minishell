/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:34:16 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/19 17:54:42 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
