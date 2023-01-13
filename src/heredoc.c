/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:55:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/12 21:23:23 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(char **line, int fd, int *pd)
{
	int index;

	index = 0;
	while (line[index])
	{
		if (!ft_strcmp(line[index], ">"))
			ft_greater(line, fd, pd);
		//else if (!ft_strcmp(lines[index], ">>"))
			//ft_double_greater(lines, fd, pd);
		//else if (!ft_strcmp(lines[index], "<"))
			//ft_less(lines, fd, pd);
		//else if (!ft_strcmp(lines[index], "<<"))
			//ft_double_less(lines, fd, pd);
		index++;
	}
}