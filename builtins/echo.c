/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:56 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/08 08:38:18 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_echo(char *line)
{
    size_t i;

    i = 5;
    if (i < ft_strlen(line) && line[i])
    {
        check_option(line, &i);
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
    if (i >= ft_strlen(line) || check_option(line, NULL) == -1)
        printf("\n");
    return (0);
}

int check_option(char *line, size_t *pos)
{
    int i;

    i = 5;
    if (line[i] && line[i + 1] && line[i] == '-' && line[i + 1] == 'n')
    {
        if (*pos)
            *pos = 8;
        return (0);
    }
    return (-1);
}