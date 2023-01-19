/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:42:12 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/19 08:00:11 by anastacia        ###   ########.fr       */
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
	int	i;

	if (line == NULL)
	{
		write(1, "exit\n", 5);
		return (1);
	}
	i = 0;
	while (ft_whitespace(line[i]))
		i++;
	if (!line[i])
		return (2);
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
		if (check_null_line(line) == 1)
			break ;
		if (!ft_strlen(line) || check_null_line(line) == 2)
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
