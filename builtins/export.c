/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:01 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/17 18:38:12 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_export(char *str)
{
	int len;
	char 	**copy;
	int index;
	
	index = 0;
	len = array_len(data()->expo) + 1;
	copy = data()->expo;
	data()->expo = ft_realloc(data()->expo, len + 1);
	while (index < len - 1)
	{
		data()->expo[index] = ft_strdup(copy[index]);
		index++;
	}
	data()->expo[len - 1] = ft_strdup(str);
	data()->expo[len] = 0;
	ft_alphabetic(data()->expo);
}

void	print_export(void)
{
	int index;

	index = 0;
	while (data()->expo[index])
	{
		printf("declare -x %s\n", data()->expo[index]);
		index++;
	}
}

int	check_export_args(char **args, size_t len)
{
	size_t	index;
	int		flag;

	flag = 0;
	index = 0;
	while (index++ < len - 1)
	{
		if (!ft_isalpha(args[index][0]))
		{
			printf("export: `%s': not a valid identifier\n", args[index]);
			flag = 1;
		}
		else
			add_export(args[index]);
	}
	if (flag)
		return (1);
	return (0);
}

int	ft_export(char *line)
{
	char	**args;
	size_t	len;

	if (check_cmd_name(line, "export ", 7))
		return (127);
	args = ft_split(line, ' ');
	len = array_len(args);
	if (len != 1)
	{
		if (!check_export_args(args, len))
		{
			free_array(args);
			return (0);
		}
		free_array(args);
		return (1);
	}
	else
		print_export();
	free_array(args);
	return (0);
}
