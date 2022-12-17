/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:42:12 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/17 18:49:47 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	data()->env = env;
	data()->expo = ft_expo_list(env);
	data()->prompt = NULL;
	data()->exit_status = 0;
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
