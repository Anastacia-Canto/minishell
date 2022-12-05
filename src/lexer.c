/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/04 18:52:45 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	break_line(char *line)
{
	check_exit(line);
	init_data();
	data()->input->src = ft_strdup(line);
	data()->input->size = ft_strlen(data()->input->src);
	data()->input->pos = 0;
	if (!data()->input->src)
		return ;
	printf("%s\n", data()->input->src);
}
