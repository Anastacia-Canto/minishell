/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:11:01 by sde-mull          #+#    #+#             */
/*   Updated: 2023/01/28 21:41:44 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_or_add(char *arg, int flg, char ***str)
{
	int	check;
	int	index;

	index = 0;
	check = check_value_list(arg, *str);
	if (flg && check == 1)
	{
		while (arg[index++])
		{
			if (arg[index] == '=')
			{
				*str = add_to_list(arg, *str);
				break ;
			}
		}
	}
	else if (check == 2)
		*str = change_list(arg, *str);
	else if (check == 1)
		*str = add_to_list(arg, *str);
	return (0);
}

void	print_char(char *str, int fd)
{
	int	index;
	int	flg;

	index = 0;
	flg = 0;
	while (str[index])
	{
		write(fd, &str[index], 1);
		if (str[index] == '=' && flg == 0)
		{
			write(fd, "\"", 1);
			flg = 1;
		}
		index++;
	}
	if (flg == 1)
	{
		write(fd, "\"", 1);
		flg = 0;
	}
}

void	print_export(int fd)
{
	int	index;

	index = 0;
	while (data()->expo[index])
	{
		write(fd, "declare -x ", 11);
		print_char(data()->expo[index], fd);
		write(fd, "\n", 1);
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

int	ft_export(char **line, int fd)
{
	size_t	len;

	len = array_len(line);
	if (len != 1)
	{
		if (!check_export_args(line, len))
			return (0);
		return (1);
	}
	else
		print_export(fd);
	return (0);
}
