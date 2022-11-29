/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:33 by anastacia         #+#    #+#             */
/*   Updated: 2022/11/29 18:55:15 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	break_line(char *line)
{
	t_list	**words;
	char	**arr;
	int		i;

	words = NULL;
	arr = ft_split(line, ' ');
	i = 0;
	while (arr[i])
	{
		ft_lstadd_back(words, ft_lstnew(arr[i]));
		free (arr[i]);
		i++;
	}
	free (arr);
	print_list(words);
	free_list(words);
}
