/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:18:00 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/18 01:14:45 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_values(char **env)
{
	data()->env = ft_list(env);
	data()->expo = ft_list(env);
	ft_alphabetic(data()->expo);
	data()->prompt = NULL;
	data()->exit_status = 0;
}

void	ft_swap_alpha(char **copy, size_t i, size_t j)
{
	int		index;
	char	*temp;

	index = 0;
	if (copy[i][index] <= copy[j][index])
	{
		while (copy[i][index] == copy[j][index] &&
			copy[i][index] && copy[j][index])
			index++;
		if (copy[i][index] <= copy[j][index])
		{
			temp = copy[i];
			copy[i] = copy[j];
			copy[j] = temp;
		}
	}
}

void	ft_alphabetic(char **copy)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[j])
		{
			ft_swap_alpha(copy, i, j);
			j++;
		}
		i++;
	}
}

char	**ft_list(char **ex_list)
{
	size_t len;
	char 	**copy;
	size_t index;
	
	index = 0;
	len = array_len(ex_list);
	copy = malloc(sizeof(char *) * len + 1);
	if (!copy)
		return (NULL);
	while (index < len - 1)
	{
		copy[index] = ft_strdup(ex_list[index]);
		index++;
	}
	copy[index] = 0;
	return (copy);
}

void	add_to_list(char *str, int check, char **lista)
{
	int		len;
	char 	**copy;
	int		index;
	
	index = 0;
	if (check_value_list(str, lista))
				return ;
	len = array_len(lista) + 2;
	copy = malloc(sizeof(char *) * len);
	while (lista[index])
	{
		copy[index] = ft_strdup(lista[index]);
		index++;
	}
	copy[index] = ft_strdup(str);
	copy[index + 1] = 0;
	check_list(check, copy);
	free_array(lista);
}