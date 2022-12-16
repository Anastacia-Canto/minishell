/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:01 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/16 15:46:40 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(void)
{
	
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
	if (len != 1 && check_export_args(args, len))
	{
		free_array(args);
		return (1);
	}
	else
		print_export();
	free_array(args);
	return (0);
}
