/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:42:17 by ansilva-          #+#    #+#             */
/*   Updated: 2023/02/09 11:51:26 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_env(int dollars, char *arg)
{
	char	*new_arg;
	char	*temp;
	int		i;

	new_arg = ft_strdup(arg);
	while (dollars > 0)
	{
		temp = ft_strdup(new_arg);
		free(new_arg);
		dollars--;
		i = 0;
		while (temp[i] && temp[i] != '$')
			i++;
		new_arg = expand_cli_env(temp, i);
		i++;
		free(temp);
	}
	free (arg);
	if (!new_arg)
		return (NULL);
	return (new_arg);
}
