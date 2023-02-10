/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:53:37 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/10 17:41:23 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *line)
{
	int		nbr_cmds;
	char	***cmds;

	data()->args_p = malloc(sizeof(char *) * 100);
	if (!data()->args_p)
		return ;
	ft_split_args(line);
	if (!check_pipe_on_args(data()->args_p))
	{
		nbr_cmds = count_cmds(data()->args_p);
		cmds = list_cmds(data()->args_p, nbr_cmds);
		if (cmds)
		{
			if (nbr_cmds == 1)
				execution(cmds[0], NULL);
			else
				ft_pipe(cmds, nbr_cmds);
			free_cmds_list(cmds, nbr_cmds);
		}
	}
	free_array(data()->args_p);
}

void	print_cmds(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		print_args(cmds[i]);
		i++;
	}
}

void	ft_split_args(char *line)
{
	int		i;

	data()->temp = malloc(sizeof(char) * 1024);
	if (!data()->temp)
		return ;
	i = 0;
	data()->p_args = 0;
	data()->p_temp = 0;
	while (line[i])
	{
		while (line[i] && ft_whitespace(line[i]))
			i++;
		if (!line[i])
			break ;
		copy_arg(line, &i);
		if (line[i] == '|' || line[i] == '>' || line[i] == '<')
			split_pipe(line, &i);
		if (!line[i] || ft_whitespace(line[i]))
			finalize_arg();
	}
	free(data()->temp);
	data()->args_p[data()->p_args] = 0;
}

int	check_end_quote(char *line, int *pos)
{
	int	i;

	i = *pos + 1;
	while (line[i] && line[i] != line[*pos])
		i++;
	if (line[i] != line[*pos])
	{
		*pos = *pos + 1;
		return (1);
	}
	if (is_quote(line[*pos]) == 1)
		data()->expand = 0;
	return (0);
}

int	is_quote(char c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}
