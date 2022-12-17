/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:12:33 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/17 17:31:58 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

char	**ft_expo_list(char **ex_list)
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
	ft_alphabetic(copy);
	return (copy);
}