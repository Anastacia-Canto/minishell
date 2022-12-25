/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:01 by sde-mull          #+#    #+#             */
/*   Updated: 2022/12/25 19:39:16 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_or_add(char *arg, int flg, char ***str)
{
	int check;
	int index;

	index = 0;
	check = check_value_list(arg, *str);
	if (flg && check == 0)
	{
		while (arg[index++])
			if (arg[index] == '=')
				*str = add_to_list(arg, *str);
	}
	else if (check == 2)
		*str = change_list(arg, *str);
	else if (check == 0)
		*str = add_to_list(arg, *str);
	return (0);
}

void	print_char(char *str)
{
	int index;
	int flg;

	index = 0;
	flg = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		if (str[index] == '=')
		{
			write(1, "\"", 1);
			flg = 1;
		}
		index++;
	}
	if (flg == 1)
	{
		write(1, "\"", 1);
		flg = 0;
	}
}

void	print_export(void)
{
	int index;

	index = 0;
	while (data()->expo[index])
	{
		write(1, "declare -x ", 11);
		print_char(data()->expo[index]);
		write(1, "\n", 1);
		index++;
	}
	index = 0;
	write(1, "divisionnn\n", 11);
	while (data()->vars[index])
	{
		print_char(data()->vars[index]);
		write(1, "\n", 1);
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
		if (!check_str(args[index]))
		{
			printf("export: `%s': not a valid identifier\n", args[index]);
			flag = 1;
		}
		else
		{
			change_or_add(args[index], 0, &data()->expo);
			change_or_add(args[index], 1, &data()->env);
			change_or_add(args[index], 1, &data()->vars);
			ft_alphabetic(data()->expo);
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
