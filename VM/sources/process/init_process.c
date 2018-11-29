/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:09 by vduong            #+#    #+#             */
/*   Updated: 2018/11/29 16:35:58 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc		*init_process(t_vm *vm, int pc, int player)
{
    static int		id = 1;
    t_proc			*new;

    if (!(new = (t_proc *)malloc(sizeof(t_proc))))
        error("malloc failed\n");
    ft_bzero(new, sizeof(t_proc));
    new->r[0] = player;
    new->id = id++;
    new->pc = pc;
    new->opcode = vm->ram[pc].content;
	vm->ram[pc].glow = 1;
    new->cycle = new->opcode > 0 && new->opcode <= 16 ?
		op_tab[(int)new->opcode - 1].cycles : 1;
    new->player = player;
    new->next = NULL;
    new->previous = NULL;
    //printf("Process created with pc = %d, opcode = %#x, cycle = %d, current vm cycle = %d\n",
    //new->pc, new->opcode, new->cycle, vm->cycles_total);
    return (new);
}
