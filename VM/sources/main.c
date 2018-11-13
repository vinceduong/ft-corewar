/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:50:56 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/13 15:50:19 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

int ft_start(char **av, t_vm *vm)
{
	if (parser(av, vm) == 0)
		return (0);
}

int main(int ac, char **av)
{
	t_vm vm;

	if (ac <= 3)
	{
		if (ft_start(av, &vm) == 0)
			ft_error(1);
	}
	else
		ft_error(1);
	return (0);
}
