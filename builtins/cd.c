/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:19:09 by ansilva-          #+#    #+#             */
/*   Updated: 2023/02/11 12:11:28 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **line)
{
	char	*path;
	int		len;

	len = array_len(line);
	if (len > 2)
	{
		write(1, "bash: cd: too many arguments\n", 29);
		return (1);
	}
	if (len == 1 || (len == 2 && !ft_strncmp(line[1], "~", sizeof(line[1]))))
	{
		path = getenv("HOME");
		chdir(path);
	}
	else if (chdir(line[1]) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", line[1]);
		return (1);
	}
	change_prompt();
	return (0);
}

void	change_prompt(void)
{
	char	*path;
	char	*prompt;
	char	*buff;

	if (data()->prompt != NULL)
		free (data()->prompt);
	prompt = ": \033[1;33mminishell$\033[0m ";
	path = NULL;
	path = getcwd(path, 0);
	buff = ft_strjoin(path, prompt);
	data()->prompt = buff;
	free (path);
}
