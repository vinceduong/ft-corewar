/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:38:02 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/15 12:25:44 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int ft_start(t_vm *vm, char **av)
{
	if (ft_parser(vm, av) == 0)
		return (0);
	/*if (ft_init_map(vm) == 0)
		return (0);
	if (ft_prepare_champ(vm) == 0)
		return (0);
	if (ft_loop(vm) == 0)
		return (0);
	if (ft_winner(vm) == 0)
		return (0);*/
	return (1);
}
