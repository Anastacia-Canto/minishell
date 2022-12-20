/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:34:16 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/20 04:00:24 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_equal(char *str, char *lista_str)
{
	int index;

	index = 0;
	while (str[index] == lista_str[index])
	{
		if (str[index] == '=' && lista_str[index] == '=')
			return (1);
		index++;
	}
	if (str[index] == '=' && lista_str[index] == '\0')
		return (1);
	return (0);
}

char	**change_list(char *str, char **lista)
{
	int		len;
	char 	**copy;
	int		index;
	
	index = 0;
	len = array_len(lista) + 1;
	copy = malloc(sizeof(char *) * len);
	if (!copy)
		return (NULL);
	while (lista[index])
	{
		if (find_equal(str, lista[index]))
		{
			copy[index] = ft_strdup(str);
			index++;
			continue;
		}
		copy[index] = ft_strdup(lista[index]);
		index++;
	}
	copy[index] = 0;
	free_array(lista);
	return (copy);
}

char	**remove_from_list(char *str, char **lista)
{
	int		len;
	char 	**copy;
	int		index;
	int		index2;
	
	index = 0;
	index2 = 0;
	len = array_len(lista);
	copy = malloc(sizeof(char *) * len);
	if (!copy)
		return (NULL);
	while (lista[index2])
	{
		if (ft_strcmp(lista[index], str))
			index2++;	
		copy[index] = ft_strdup(lista[index2]);
		index++;
		index2++;
	}
	copy[index] = 0;
	free_array(lista);
	return (copy);
}