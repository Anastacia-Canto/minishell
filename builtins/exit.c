/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:10:03 by ansilva-          #+#    #+#             */
/*   Updated: 2022/12/07 12:26:13 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_exit(char *line)
{
    printf("%s\n", line);
    free (line);
    rl_clear_history();
	exit(EXIT_SUCCESS);
    return (0);
}