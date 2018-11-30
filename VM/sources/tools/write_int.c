/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:07:31 by vduong            #+#    #+#             */
/*   Updated: 2018/11/30 15:26:15 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void write_int(t_vm *vm, int adress, int n, int player)
{
    vm->ram[mod_pc(adress + 3)].content = n & 0x000000ff;
	vm->ram[mod_pc(adress + 3)].pid = player;
	vm->ram[mod_pc(adress + 2)].content = (n & 0x0000ff00) >> 8;
	vm->ram[mod_pc(adress + 2)].pid = player;
	vm->ram[mod_pc(adress + 1)].content = (n & 0x00ff0000) >> 16;
	vm->ram[mod_pc(adress + 1)].pid = player;
	vm->ram[mod_pc(adress)].content = (n & 0xff000000) >> 24;
	vm->ram[mod_pc(adress)].pid = player;
}