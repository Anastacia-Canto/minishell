/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:51:56 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/27 16:00:15 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(void)
{
	if (data()->expo)
		free_array(data()->expo);
	if (data()->env)
		free_array(data()->env);
	if (data()->vars)
		free_array(data()->vars);
}