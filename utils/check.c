/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:38:36 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/25 19:36:29 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_value_list(char *str, char **lista)
{
	int	index;
	int cmp;

	index = 0;
	while (lista[index])
	{
		cmp = ft_strcmp_expo(lista[index], str);
		if (cmp == 0)
			return (1);
		else if (cmp == 2)
			return (2);
		index++;
	}
	return (0);
}

int	check_str(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '=')
		return (0);
	while (str[index])
	{
		if (str[index] == '=')
			return (1);
		else if (!ft_isalnum(str[index]) && str[index] != '_')
			return (0);
		index++;
	}
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	return (1);
}

int	check_line(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == ' ')
			return(1);
		index++;
	}
	return (0);
}