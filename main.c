/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:42:12 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/23 14:24:45 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	init_values(env);
	if (env)
	{
		change_prompt();
		line = readline(data()->prompt);
		while (line)
		{
			add_history(line);
			break_in_cmd(line);
			line = readline(data()->prompt);
		}
		free (data()->prompt);
		rl_clear_history();
	}
	return (0);
}
