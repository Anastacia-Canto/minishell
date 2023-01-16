/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:42:12 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/16 17:43:33 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sigint(int sig)
{
	if (sig == SIGINT && data()->sig == 0)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		data()->exit_status = 130;
	}
}

int	check_null_line(char *line)
{
	if (line == NULL)
	{
		write(1, "exit\n", 5);
		return (1);
	}
	return (0);
}

void	main_loop(void)
{
	char	*line;

	while (1)
	{
		signal(SIGINT, handler_sigint);
		signal(SIGQUIT, SIG_IGN);
		line = readline(data()->prompt);
		if (check_null_line(line))
			break ;
		if (!ft_strlen(line))
		{
			free(line);
			continue ;
		}
		add_history(line);
		parser(line);
		free(line);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init_values(env);
	if (env)
	{
		change_prompt();
		main_loop();
		free (data()->prompt);
		rl_clear_history();
	}
	return (0);
}
