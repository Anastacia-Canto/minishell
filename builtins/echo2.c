/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:17:29 by anastacia         #+#    #+#             */
/*   Updated: 2022/12/20 16:44:20 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(char c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}

void	args_parser(char *line)
{
	char	*arg;
	size_t	pos;
	t_args	**list;

	list = NULL;
	pos = 0;
	while (pos < ft_strlen(line) && line[pos])
	{
		arg = get_arg(line, &pos);
		if (arg)
		{
			add_arg(list, new_arg(arg));
			free (arg);
		}
	}
	print_list(list);
	clear_list(list);
}

void	clear_list(t_args **list)
{
	t_args	*temp;

	if (!list || !*list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free (*list);
		*list = temp;
	}
}

void	print_list(t_args **list)
{
	t_args	*temp;

	if (!list || !*list)
		return ;
	temp = *list;
	while (temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}
}

char	*get_arg(char *line, size_t *pos)
{
	char	quote;
	size_t	i;
	char	*str;

	i = *pos;
	if (is_quote(line[i]))
	{
		if (is_quote(line[i]) == 1)
			data()->expand = 0;
		quote = line[i++];
		while (i < ft_strlen(line) && line[i] != quote)
			i++;
	}
	else
	{
		while (i < ft_strlen(line) && !ft_whitespace(line[i]) && !is_quote(line[i]))
			i++;
	}
	if (i - (*pos) > 1)
	{
		// if (ft_whitespace(line[i]))
		// 	i++;
		str = ft_substr(line, *pos, i - (*pos));
		*pos = i + 1;
		return (str);
	}
	*pos = i + 1;
	return (NULL);
}

t_args	*new_arg(char *content)
{
	t_args	*new_node;

	new_node = (t_args *)malloc(sizeof(t_args));
	new_node->content = malloc(sizeof(char *));
	if (new_node == NULL || new_node->content == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	add_arg(t_args **lst, t_args *new)
{
	t_args	*temp;

	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
