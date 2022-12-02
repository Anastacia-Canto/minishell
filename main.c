/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:42:12 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/02 16:18:53 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	(void)env;
	line = readline("[minishell][:)]~> ");
	while (line)
	{
		add_history(line);
		break_line(line);
		free (line);
		line = readline("[minishell][:)]~> ");
	}
	rl_clear_history();
	free (line);
	return (0);
}
