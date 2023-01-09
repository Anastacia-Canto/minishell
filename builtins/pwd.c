/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:21:25 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/09 16:59:31 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char *line, int fd)
{
	char	*path;
	size_t	len;

	if (check_cmd_name(line, "pwd ", 4))
		return (127);
	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		return (1);
	len = ft_strlen(path);
	write(fd, path, len);
	write(fd, "\n", 1);
	free (path);
	return (0);
}
