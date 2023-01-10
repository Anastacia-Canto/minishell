/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:19:09 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/10 16:54:33 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char *line)
{
	size_t	i;
	char	*path;

	i = 3;
	if (check_cmd_name(line, "cd ", 3))
		return (127);
	if (i < ft_strlen(line))
	{
		path = ft_substr(line, i, ft_strlen(line) - i + 1);
		if (chdir(path) == -1)
			printf("minishell: cd: %s: No such file or directory\n", path);
		change_prompt();
		free (path);
		return (1);
	}
	path = getenv("HOME");
	chdir(path);
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