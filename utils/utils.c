/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:38:19 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/02 15:06:57 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_data	*data(void)
// {
// 	static t_data	data;

// 	return (&data);
// }

void	print_list(t_lst *list)
{
	t_lst	*temp;

	temp = list;
	while (temp != NULL)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}
}

void	free_list(t_lst **list)
{
	t_lst	*temp;

	if (!list || !*list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free (*list);
		*list = temp;
	}
}

t_lst	*new_node(char *content)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}

t_lst	*add_back(t_lst **list, t_lst *new)
{
	t_lst	*temp;

	if (!new)
		return (NULL);
	if (!list)
		return (new);
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (*list);
}

void	check_exit(char *line)
{
	if (!ft_strncmp(line, "exit\n", 4))
	{
		free (line);
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
}
