/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:55:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/13 08:21:37 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(char **line, int *pd)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (!ft_directcmp(line[index], ">"))
			ft_greater(line, pd);
		else if (!ft_directcmp(line[index], ">>"))
			ft_double_greater(line, pd);
		else if (!ft_directcmp(line[index], "<"))
			ft_less(line, pd);
		else if (!ft_directcmp(line[index], "<<"))
			ft_double_less(line, pd);
		index++;
	}
}
