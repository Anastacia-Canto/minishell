/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/12 12:06:49 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char *line)
{
    int     option;
    size_t  i;

    i = 5;
    option = 0;
	if (!ft_strncmp(line, "echo -n", 7))
    {
        option = 1;
        i = 8;
    }
    if (i < ft_strlen(line))
    {
        while (line[i])
        {
            if (line[i] == '$')
            {
                if (ft_expand_env(line, &i) == 1)
                    break ;
            }
            if (line[i])
                printf("%c", line[i++]);
        }
    }
    if (option == 0)
        printf("\n");
    return (0);
}

