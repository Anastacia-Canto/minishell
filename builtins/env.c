/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:17 by ansilva-          #+#    #+#             */
/*   Updated: 2023/01/13 11:07:08 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_envs(char **env, char **line, int fd)
{
	int		i;
	size_t	len;

	if (!env || !*env)
		return (1);
	if (array_len(line) > 1)
	{
		printf("env: '%s': No such file or directory\n", line[1]);
		return (127);
	}
	i = 0;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		write(fd, env[i++], len);
		write(fd, "\n", 1);
	}
	return (0);
}
