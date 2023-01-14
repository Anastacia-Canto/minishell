/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:55:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/14 04:51:47 by sde-mull         ###   ########.fr       */
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
		if (data()->break_flg)
		{
			data()->break_flg = 0;
			break ;
		}
		index++;
	}
}
