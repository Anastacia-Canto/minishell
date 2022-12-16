/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:21:25 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/16 15:47:49 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char *line)
{
	char	*path;

	if (check_cmd_name(line, "pwd ", 4))
		return (127);
	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		return (1);
	printf("%s\n", path);
	free (path);
	return (0);
}
