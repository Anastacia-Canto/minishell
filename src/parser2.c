/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:14:34 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/19 16:15:32 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	end_heredoc(char *line, int i)
{
	if (i == (int)ft_strlen(line) - 1)
		return (0);
	if (line[i] == '>' && line[i + 1] != '>' && !ft_whitespace(line[i + 1]))
		return (1);
	else if (line[i] == '<' && line[i + 1] != '<'
		&& !ft_whitespace(line[i + 1]))
		return (1);
	return (0);
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

void	free_cmds_list(char ***cmds, int nbr_cmds)
{
	int	i;

	if (!cmds || !**cmds)
		return ;
	i = 0;
	while (i < nbr_cmds)
	{	
		free_array(cmds[i]);
		i++;
	}
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
	cmd[i] = 0;
	return (cmd);
}

void	finalize_arg(char *temp, int *j, char **args, int *k)
{
	temp[*j] = '\0';
	args[*k] = ft_strdup(temp);
	if (data()->expand)
		args[*k] = check_if_env(args[*k]);
	if (!args[*k])
	{
		free(args[*k]);
		*k = *k - 1;
	}
	*k = *k + 1;
	*j = 0;
	data()->expand = 1;
}

void	copy_arg(char *line, int *i, char *temp, int *j)
{
	int	k;
	int	w;

	k = *i;
	w = *j;
	if (is_quote(line[k]) && !check_end_quote(line, &k))
	{
		while (line[++k] && !is_quote(line[k]))
			temp[w++] = line[k];
		*i = k + 1;
		*j = w;
	}
	else
	{
		while (line[k] && !ft_whitespace(line[k]) && !is_quote(line[k]))
		{
			temp[w++] = line[k++];
			if (end_heredoc(line, k - 1))
				break ;
		}
		*i = k;
		*j = w;
	}
}
