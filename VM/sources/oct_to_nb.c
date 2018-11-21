/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_to_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:46 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/21 14:32:05 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

short		to_short(t_vm *vm, int pc)
{
	char tab[2];

	tab[0] = vm->ram[(pc + 1) % MEM_SIZE].content;
	tab[1] = vm->ram[pc].content;
	return (*((short*)tab));
}

int			to_int(t_vm *vm, int pc)
{
	char tab[4];

	tab[0] = vm->ram[(pc + 3) % MEM_SIZE].content;
	tab[1] = vm->ram[(pc + 2) % MEM_SIZE].content;
	tab[2] = vm->ram[(pc + 1) % MEM_SIZE].content;
	tab[3] = vm->ram[pc].content;
	return (*((int*)tab));
}
