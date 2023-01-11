/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:42:12 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/11 01:16:25 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		data()->exit_status = 130;
	}
}

void	handler_sigquit(int sig)
{
	if (sig == SIGQUIT)
	{
		write(1, "HERE", 4);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	init_values(env);
	if (env)
	{
		change_prompt();
		
		signal(SIGINT, handler_sigint);
		line = readline(data()->prompt);
		while (line)
		{
			add_history(line);
			break_in_cmd(line);
			line = readline(data()->prompt);
		}
		free (data()->prompt);
		clear_history();
	}
	return (0);
}
