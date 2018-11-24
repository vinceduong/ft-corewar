/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:46 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/24 09:49:04 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			read_int(t_vm *vm, int pc)
{
	char tab[4];

	tab[0] = vm->ram[(pc + 3) % MEM_SIZE].content;
	tab[1] = vm->ram[(pc + 2) % MEM_SIZE].content;
	tab[2] = vm->ram[(pc + 1) % MEM_SIZE].content;
	tab[3] = vm->ram[pc].content;
	return (*((int*)tab));
}
