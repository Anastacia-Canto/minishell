/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:38:19 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/06 15:10:37 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_data	*data(void)
// {
// 	static	*data;

// 	return (&data);
// }

void	check_exit(char *line)
{
	if (!ft_strncmp(line, "exit", 4))
	{
		free (line);
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
}

char	*fix_spaces(char *line)
{
	char	*new_line;
	int		i;
	int		j;
	int		flag;

	new_line = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!line || !new_line)
		return (NULL);
	flag = 0;
	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] && ft_whitespace(line[i]))
		{
			if (flag == 1)
			{
				new_line[j] = line[i];
				j++;
				flag = 0;
			}
			i++;
		}
		while (line[i] && !ft_whitespace(line[i]))
		{
			new_line[j] = line[i];
			j++;
			i++;
			flag = 1;
		}
	}
	new_line[j] = '\0';
	return (new_line);
}