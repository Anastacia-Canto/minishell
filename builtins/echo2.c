/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:52:00 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/10 11:52:29 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_special_sign(char **line)
{
	int	i;
	int	sig;

	i = 0;
	while (line[i])
	{
		sig = 0;
		if (!ft_strncmp(line[i], "\'>\'", sizeof(line[i]))
			|| !ft_strncmp(line[i], "\">\"", sizeof(line[i])))
				sig = 1;
		else if (!ft_strncmp(line[i], "\'>>\'", sizeof(line[i]))
			|| !ft_strncmp(line[i], "\">>\"", sizeof(line[i])))
				sig = 2;
		else if (!ft_strncmp(line[i], "\'<\'", sizeof(line[i]))
			|| !ft_strncmp(line[i], "\"<\"", sizeof(line[i])))
				sig = 3;
		else if (!ft_strncmp(line[i], "\'<<\'", sizeof(line[i]))
			|| !ft_strncmp(line[i], "\"<<\"", sizeof(line[i])))
				sig = 4;
		if (sig)
			change_special_sign(line, i, sig);
		i++;
	}
}

void	change_special_sign(char **line, int i, int sig)
{
	free(line[i]);
	if (sig == 1)
		line[i] = ft_strdup(">");
	else if (sig == 2)
		line[i] = ft_strdup(">>");
	else if (sig == 3)
		line[i] = ft_strdup("<");
	else if (sig == 4)
		line[i] = ft_strdup("<<");
}
