/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:42:12 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/16 13:52:23 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	data()->env = env;
	data()->prompt = NULL;
	if (env)
	{
		change_prompt();
		line = readline(data()->prompt);
		while (line)
		{
			add_history(line);
			break_line(line);
			line = readline(data()->prompt);
		}
		free (data()->prompt);
		rl_clear_history();
	}
	return (0);
}
