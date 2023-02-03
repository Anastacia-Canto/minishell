/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:22:39 by anastacia         #+#    #+#             */
/*   Updated: 2023/02/03 11:04:25 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe_on_args(char **args)
{
	int	i;
	int	len;

	if (ft_strncmp(args[0], "|", sizeof(args[0]) || args[0][0] != '|'))
	{
		len = array_len(args);
		i = 1;
		while (i < len)
		{
			if (i < len && ((!ft_strncmp(args[i], "|", sizeof(args[i]))
						&& !ft_strncmp(args[i + 1], "|", sizeof(args[i + 1])))
					|| (ft_strlen(args[i]) > 1 && args[i][1] == '|')))
				break ;
			else if (i == len -1 && !ft_strncmp(args[i], "|", sizeof(args[i])))
				break ;
			i++;
		}
		if (i == len)
			return (0);
	}
	printf("bash: syntax error near unexpected token `|'\n");
	return (1);
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
