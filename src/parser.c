/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:53:37 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/03 12:09:23 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *line)
{
	char	**args;
	int		nbr_cmds;
	char	***cmds;

	args = malloc(sizeof(char *) * 100);
	if (!args)
		return ;
	ft_split_args(line, args);
	print_args(args);
	if (!check_pipe_on_args(args))
	{
		nbr_cmds = count_cmds(args);
		cmds = list_cmds(args, nbr_cmds);
		// print_cmds(cmds);
		if (cmds)
		{
			ft_pipe(cmds, nbr_cmds);
			free_cmds_list(cmds, nbr_cmds);
		}
	}
	free_array(args);
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

void	ft_split_args(char *line, char **args)
{
	char	*temp;
	int		i;
	int		j;
	int		k;

	temp = malloc(sizeof(char) * 1024);
	if (!temp)
		return ;
	i = 0;
	k = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] && ft_whitespace(line[i]))
			i++;
		if (!line[i])
			break ;
		copy_arg(line, &i, temp, &j);
		if (!line[i] || ft_whitespace(line[i]) || end_heredoc(line, i - 1) == 1)
			finalize_arg(temp, &j, args, &k);
	}
	free(temp);
	args[k] = 0;
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

int	count_cmds(char **args)
{
	int	i;
	int	cmds;

	i = -1;
	cmds = 1;
	while (args[++i])
	{
		if (!ft_strncmp(args[i], "|", sizeof(args[i])))
			cmds++;
	}
	return (cmds);
}
