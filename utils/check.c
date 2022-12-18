/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:38:36 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/18 01:59:22 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_list(int check, char **lista)
{
	if (check == 1)
		data()->expo = lista;
	else if (check == 2)
		data()->env = lista;
}

int	check_value_list(char *str, char **lista)
{
	int index;

	index = 0;
	while(lista[index])
	{
		if (!ft_strcmp(lista[index], str))
			return (1);
		index++;
	}
	return (0);
}

int	check_str(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!ft_isalnum(str[index]) && str[index] != '_')
			return (0);
		index++;
	}
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	return (1);
}
