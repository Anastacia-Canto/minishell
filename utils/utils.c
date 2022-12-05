/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:38:19 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/04 18:48:18 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	init_data(void)
{
	data()->input = malloc(sizeof(t_input));
	data()->tokens = malloc(sizeof(t_list));
}

void	check_exit(char *line)
{
	if (!ft_strncmp(line, "exit\n", 4))
	{
		free (line);
		free (data()->input->src);
		free (data()->input);
		free (data()->tokens);
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
}
