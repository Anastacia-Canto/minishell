/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:38:19 by anastacia         #+#    #+#             */
/*   Updated: 2022/11/29 18:55:00 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_words	*words(void)
// {
// 	static t_words	words;

// 	return (&words);
// }

void	print_list(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}

void	free_list(t_list **list)
{
	t_list	*temp;

	if (!list || !*list)
		return ;
	while (list && *list)
	{
		temp = (*list)->next;
		free (*list);
		*list = temp;
	}
}