/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:53:37 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/12 17:47:59 by anastacia        ###   ########.fr       */
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
	// printf("%d\n", nbr_cmds);
	if (nbr_cmds == 1)
		to_builtins(args, 1, NULL);
	else
	{
		cmds = list_cmds(args, nbr_cmds);
		ft_pipe(cmds, nbr_cmds);
		free_cmds_list(cmds);
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
		if (is_quote(line[i]) && !check_end_quote(line, &i))
		{
			i++;
			while (line[i] && !is_quote(line[i]))
				temp[j++] = line[i++];
			if (!line[i + 1] || ft_whitespace(line[i + 1]))
			{
				temp[j] = '\0';
				args[k] = ft_strdup(temp);
				k++;
				j = 0;
			}
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
				k++;
				j = 0;
			}
		}
	}
	free(temp);
	args[k] = '\0';
	return (args);
}

void	print_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		printf("args[%d]: %s\n", i, args[i]);
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

char	***list_cmds(char **args, int nbr_cmds)
{
	char	***cmds;
	int		i;
	int		start;
	int		end;

	cmds = malloc(sizeof(char **) * nbr_cmds);
	if (!cmds)
		return (NULL);
	i = -1;
	start = 0;
	end = start;
	while (++i < nbr_cmds)
	{
		while (args[end] && ft_strncmp(args[end], "|", sizeof(args[end])))
			end++;
		cmds[i] = split_cmds(args, start, end - start);
		end++;
		start = end;
	}
	return (cmds);
}

void	free_cmds_list(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		free_array(cmds[i++]);
	free (cmds);
}

char	**split_cmds(char **line, int start, int len)
{
	char	**cmd;
	int		i;

	cmd = malloc(sizeof(char *) * (len + 1));
	if (!cmd)
		return (NULL);
	i = -1;
	while (++i < len)
		cmd[i] = ft_strdup(line[start + i]);
	cmd[i] = '\0';
	return (cmd);
}
