/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/07 12:01:22 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_echo(char *line)
{
    int i;
    int flag;

    if (!line)
        return (2);
    flag = 0;
    i = 5;
    if (line[i] == '-' && line[i + 1] == 'n')
    {
        flag = 1;
        i = 8;
    }
    while (line[i])
        printf("%c", line[i++]);
    if (!flag)
        printf("\n");
    return (0);
}

