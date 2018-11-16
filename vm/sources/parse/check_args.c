/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:43:59 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/16 17:04:47 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int check_is_flag(char **av, int i)
{
	if (av[i][0] == '-')
		return (!ft_strcmp(av[i], "-dump") || !ft_strcmp(av[i], "-n") ? 1 : -1);
	else
		return (0);
}

static int check_is_cor(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	if (len < 5)
		return (0);
	while (i < len)
	{
		if (str[i] ==  '.' && len - i == 4)
			return (!ft_strcmp(&str[i], ".cor") ? 1 : 0);
		i++;
	}
	return (0);
}

static int check_n(char **av, int i)
{
	if (!av[i + 1] || !av[i + 2])
		return (-1);
	if(av[i + 1][1])
		return(-1);
	if(ft_atoi(av[i + 1]) < 1 || ft_atoi(av[i + 1]) > 4)
		return (-1);
	if (!check_is_cor(av[i + 2]))
	{
		return (-1);
	}
	return (1);
}

static int check_dump(char **av, int i)
{
	int j;

	j = 0;
	if (av[i + 1])
	{
		if (ft_strlen(av[i + 1]) > 10)
			return (-1);
		while (av[i  + 1][j])
		{
			if (!ft_isdigit(av[i + 1][j]))
				return (-1);
			j++;
		}
		if (ft_atoi(av[i + 1]) < 0)
			return (-1);
	}
	else
		return (-2);
	return (1);
}

int check_args(char **av, t_vm *vm)
{
	int i;
	int return_value;

	i = 1;
	while (av[i])
	{
		if ((return_value = check_is_flag(av, i)) < 0)
			return (return_value);
		else if (return_value)
		{
			if (!ft_strcmp(av[i], "-n"))
			{
				if (check_n(av, i) < 0)
					return (-1);
				if (vm->players[ft_atoi(av[i + 1]) - 1].p)
					return (-1);
				vm->players[ft_atoi(av[i + 1]) - 1].filename = ft_strdup(av[i + 2]);
				vm->players[ft_atoi(av[i + 1]) - 1].p = 1;
				vm->nbplayers++;
				i += 2;
			}
			else if (!ft_strcmp(av[i], "-dump"))
			{
				if ((return_value = check_dump(av, i)) < 0)
					return (return_value);
				vm->flag.dump = ft_atoi(av[i + 1]);
				i++;
			}
			else
			{
				if (check_is_cor(av[i]))
				{
					vm->players[vm->nbplayers].p = 1;
					vm->players[vm->nbplayers].filename = ft_strdup(av[i]);
					vm->nbplayers++;
				}
			}

		}
		i++;
	}
	return (1);
}
