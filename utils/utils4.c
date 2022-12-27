/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:10:51 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/27 10:50:50 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmd_error(char *str)
{
	int	index;

	index = 0;
	while (str[index] != ' ' && str[index])
		printf("%c", str[index++]);
	index = 0;
	printf(": command not found\n");
	return (127);
}
