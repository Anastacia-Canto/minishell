/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:53:37 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/13 18:40:45 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *line)
{
	char	**args;
	int		nbr_cmds;
	char	***cmds;

	args = ft_split_args(line);
	// print_args(args);
	nbr_cmds = count_cmds(args);
	if (nbr_cmds == 1)
		execution(args, 1, NULL);
	else
	{
		cmds = list_cmds(args, nbr_cmds);
		ft_pipe(cmds, nbr_cmds);
		free_cmds_list(cmds, nbr_cmds);
	}
	free_array(args);
}

char	**ft_split_args(char *line)
{
	char	**args;
	char	*temp;
	int		i;
	int		j;
	int		k;

	args = malloc(sizeof(char *) * 100);
	temp = malloc(sizeof(char) * 1024);
	if (!temp || !args)
		return (NULL);
	i = 0;
	k = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] && ft_whitespace(line[i]))
			i++;
		if (!line[i])
			break ;
		if (is_quote(line[i]) && !check_end_quote(line, &i))
		{
			if (is_quote(line[i]) == 1)
				data()->expand = 0;
			i++;
			while (line[i] && !is_quote(line[i]))
				temp[j++] = line[i++];
			if (!line[i + 1] || ft_whitespace(line[i + 1]))
			{
				temp[j] = '\0';
				args[k] = ft_strdup(temp);
				if (data()->expand)
					args[k] = check_if_env(args[k]);
				if (!args[k])
				{
					free(args[k]);
					k--;
				}
				k++;
				j = 0;
			}
			data()->expand = 1;
			i++;
		}
		else
		{
			while (line[i] && !ft_whitespace(line[i]))
			{
				if (is_quote(line[i]))
					break ;
				temp[j++] = line[i++];
			}
			if (!line[i] || ft_whitespace(line[i]))
			{
				temp[j] = '\0';
				args[k] = ft_strdup(temp);
				if (data()->expand)
					args[k] = check_if_env(args[k]);
				if (!args[k])
				{
					free(args[k]);
					k--;
				}
				k++;
				j = 0;
			}
		}
	}
	free(temp);
	args[k] = 0;
	return (args);
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

void	print_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		printf("args[%d]: %s\n len: %ld\n", i, args[i], ft_strlen(args[i]));
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
