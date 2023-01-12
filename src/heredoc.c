/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:55:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/12 17:47:56 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	heredoc(char **lines, int fd, int *pd)
// {
// 	int index;

// 	index = 0;
// 	while (lines[index])
// 	{
// 		if (lines[index] == ">")
// 			ft_greater(lines, fd, pd);
// 		else if (lines[index] == ">>")
// 			ft_double_greater(lines, fd, pd);
// 		else if (lines[index] == "<")
// 			ft_less(lines, fd, pd);
// 		else if (lines[index] == "<<")
// 			ft_double_less(lines, fd, pd);
// 		index++;
// 	}
// }