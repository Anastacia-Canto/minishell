/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:34:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/02 16:13:38 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_equal(char *str, char *lista_str)
{
	int	index;

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
	char	**copy;
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
			continue ;
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
	char	**copy;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	len = array_len(lista) + 1;
	copy = malloc(sizeof(char *) * len);
	if (!copy)
		return (NULL);
	while (lista[index2])
	{
		if (ft_strcmp_expo(str, lista[index2]) == 2)
		{
			if (!lista[index2 + 1])
				break ;
			index2++;
		}
		copy[index++] = ft_strdup(lista[index2++]);
	}
	copy[index] = 0;
	free_array(lista);
	return (copy);
}

int	ft_strcmp_expo(char *str, char *str2)
{
	int	index;

	index = 0;
	if (!str || !str2)
		return (0);
	while (str[index] && str2[index])
	{
		if (str[index] != str2[index])
			return (1);
		else if (str[index] == '=')
			return (2);
		index++;
	}
	if (str[index] == '\0' && str2[index] == '=')
		return (2);
	return (0);
}

char	**create_list(char *str)
{
	char	**str2;

	str2 = malloc(sizeof(char *) * 2);
	str2[0] = ft_strdup(str);
	str2[1] = 0;
	return (str2);
}
