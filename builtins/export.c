/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:01 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/16 13:55:44 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(void)
{
	
}

void	check_export_args(char **args, size_t len)
{
	size_t	index;

	index = 0;
	while (index++ < len - 1)
		if (!ft_isalpha(args[index][0]))
			printf("export: `%s': not a valid identifier\n", args[index]);
}

int	ft_export(char *line)
{
	char	**args;
	size_t	len;

	if (check_cmd_name(line, "export ", 7))
		return (1);
	args = ft_split(line, ' ');
	len = array_len(args);
	if (len != 1)
		check_export_args(args, len);
	else
		print_export();
	free_array(args);
	return (0);
}
