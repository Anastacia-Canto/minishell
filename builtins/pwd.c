/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:21:25 by anastacia         #+#    #+#             */
/*   Updated: 2023/01/12 13:28:35 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(int fd)
{
	char	*path;
	size_t	len;

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
