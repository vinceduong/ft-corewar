/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:43:59 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/14 18:51:27 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int check_is_flag(char **av, int i)
{
	if (av[i][0] == '-')
		return (!strcmp(av[i], "-dump") || !strcmp(av[i], "-n") ? 1 : -1);
	else
		return (0);
}

int check_n(char **av, int i)
{
	int j;

	j = 1;
	while (j < 2)
	{
		if (!av[i + j])
			return (-1);
		if (j == 1)
		{
			if(!av[i + j][1])
				return (-1);
			if (ft_atoi(av[i + j]) <= 0 && ft_atoi(av[i + j] => 4))
				return (-1);
		}
		else
		{
			if (!check_is_cor(av[i + j]))
				return (-1);
		}
	}
	return (1);	
}

int check_dump(char **av, int i)
{
	int j;

	if (av[i + 1])
	{
		if (ft_strlen(av[i + 1] > 10))
			return (-2);
		j = 0;
		while (av[i  + 1][j])
		{
			if (!ft_isdigit(av[i + 1][j]))
				return (-2);		
		}
		if (ft_atoi(av[i + 1] < 0))
			return (-2);
	}	
	else
		return (-1);	
	return (1);	
}

int check_args(char **av, t_vm *vm)
{
	int i;
	int j;
	int return_value;

	i = 0;
	while (av[i])
	{
		if ((return_value = check_is_flag(av, i)) < 0)
			return (return_value);
		else if (return_value)
		{
			if (strcmp(av[i], "-n")
			{
				if (check_n(av, i) < 0)
					return (-1);
			}
			if (strcmp(av[i], "-dump")
			{
				if ((return_value = check_dump(av, i)) < 0)
					return (return_value);
			}
		}	
		i++;
	}
	return (1);
}
