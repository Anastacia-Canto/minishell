/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:51:56 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/11 12:31:19 by anastacia        ###   ########.fr       */
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
