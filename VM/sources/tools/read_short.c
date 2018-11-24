/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:48:56 by vduong            #+#    #+#             */
/*   Updated: 2018/11/24 09:48:57 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

short		read_short(t_vm *vm, int pc)
{
	char tab[2];

	tab[0] = vm->ram[(pc + 1) % MEM_SIZE].content;
	tab[1] = vm->ram[pc].content;
	return (*((short*)tab));
}
