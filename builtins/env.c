/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:17 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/07 14:52:38 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_expand_env(char *line, size_t *pos)
{
    int     end;
    char    *value;
    char    *name;

    end = *pos;
    while (line[end] && !ft_whitespace(line[end]))
        end++;
    name = ft_substr(line, *pos + 1, end - *pos - 1);
    value = getenv(name);
    free (name);
    if (!value)
        return (1);
    printf("%s", value);
    *pos = end;
    return (0);
}