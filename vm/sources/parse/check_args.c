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
		return (!strcmp(av[i], "dump") || !strcmp(av[i], "-n"));
	else
		return (0);
}

int check_args(char **av, t_vm *vm)
{
	int i;
	int return_value;

	i = 0;
	while (av[i])
	{
		if ((return_value = check_is_flag) < 0)
			return (return_value);
		i++;
	}
	return (1);
}
