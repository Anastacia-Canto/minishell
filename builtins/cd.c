/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:19:09 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/15 15:39:27 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char *line)
{
	size_t	i;
	char	*path;
	char	*user;

	i = 3;
	if (check_cmd_name(line, "cd ", 3))
		return (1);
	if (i < ft_strlen(line))
	{
		path = ft_substr(line, i, ft_strlen(line) - i + 1);
		if (chdir(path) == -1)
			printf("minishell: cd: %s: No such file or directory\n", path);
	}
	else
	{
		user = getenv("USER");
		path = ft_strjoin("/nfs/homes/", user);
		chdir(path);
	}
	free (path);
	return (0);
}
