/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:05:40 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/20 03:56:01 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *str, char *str2)
{
	int index;

	index = 0;
	if (!str || !str2)
		return (0);
	while (str[index] && str2[index])
	{
		if (str[index] != str2[index])
			return (1);
		else if (str[index] == '=')
			data()->expo_flag = 1;
		index++;
	}
	if (str[index] == '\0' && str2[index] == '=')
	{
		data()->expo_flag = 1;
		return (1);
	}
	return (0);
}
