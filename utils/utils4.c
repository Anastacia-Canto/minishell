/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:10:51 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/26 11:28:54 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd_error(char *str)
{
	int index;

	index = 0;
	while (str[index] != ' ' && str[index])
		printf("%c",str[index++]);
	index = 0;
	printf(": command not found\n");
}
