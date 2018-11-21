/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:09 by vduong            #+#    #+#             */
/*   Updated: 2018/11/21 13:46:00 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc *init_process(t_vm *vm, int pc, int player)
{
    static int id = 1;
    t_proc *new;

    if (!(new = (t_proc *)malloc(sizeof(t_proc))))
        error("malloc failed\n");
    new->r[0] = player;
    new->alive = 0;
    new->id = id++;  
    new->pc = pc;
    new->carry = 0;
    new->opcode = vm->ram[pc].content;
    new->cycle = op_tab[new->opcode].cycles;
    return (new);
}