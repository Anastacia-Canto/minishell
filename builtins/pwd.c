/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:21:25 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/15 15:47:00 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char *line)
{
	char	*path;

	if (check_cmd_name(line, "cd ", 3))
		return (1);
	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		return (1);
	printf("%s\n", path);
	free (path);
	return (0);
}
