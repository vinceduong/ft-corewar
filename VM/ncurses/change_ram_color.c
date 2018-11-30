/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_ram_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:55:51 by afourcad          #+#    #+#             */
/*   Updated: 2018/11/30 18:18:44 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	change_ram_color(t_vm *vm, int pc, int pc_dest, int p_id)
{
	int	color;

	color = vm->ram_color[pc];
	color = color > 5 ? color - 5 : color;
	vm->ram_color[mod_adr(pc_dest)] = color;
	vm->ram_glow[mod_adr(pc_dest)] = GLOW_CYCLE;
	vm->ram_viewed[mod_adr(pc_dest)] = p_id;
	vm->ram_color[mod_adr(pc_dest + 1)] = color;
	vm->ram_glow[mod_adr(pc_dest + 1)] = GLOW_CYCLE;
	vm->ram_viewed[mod_adr(pc_dest + 1)] = p_id;
	vm->ram_color[mod_adr(pc_dest + 2)] = color;
	vm->ram_glow[mod_adr(pc_dest + 2)] = GLOW_CYCLE;
	vm->ram_viewed[mod_adr(pc_dest + 2)] = p_id;
	vm->ram_color[mod_adr(pc_dest + 3)] = color;
	vm->ram_glow[mod_adr(pc_dest + 3)] = GLOW_CYCLE;
	vm->ram_viewed[mod_adr(pc_dest + 3)] = p_id;
}
