/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:09 by vduong            #+#    #+#             */
/*   Updated: 2018/11/21 20:31:32 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc *init_process(t_vm *vm, int pc, int player)
{
    static int id = 1;
    t_proc *new;

    if (!(new = (t_proc *)malloc(sizeof(t_proc))))
        error("malloc failed\n");
    ft_bzero(new, sizeof(t_proc));
    new->r[0] = player;
    new->id = id++;
    new->pc = pc;
    new->opcode = vm->ram[pc].content;
    new->cycle = op_tab[new->opcode - 1].cycles;
    printf("OPCODE = %d CYCLES = %d\n", new->opcode, op_tab[new->opcode - 1].cycles);
    new->player = player;
    new->next = NULL;
    new->previous = NULL;
    return (new);
}
