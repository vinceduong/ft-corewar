/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:19:52 by vduong            #+#    #+#             */
/*   Updated: 2018/11/21 16:54:08 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void print_process(t_proc *process)
{
    printf("---PROCESS---\n");
    printf("registres = [%d][%d][%d][%d]\n", process->r[0],process->r[1],process->r[2],process->r[3]);
    printf("id = %d\n", process->id);
    printf("carry = %d\n", process->carry);
    printf("player = %d\n", process->player);
    printf("opcode = %d\n", process->opcode);
    printf("cycle = %d\n", process->cycle);
    printf("pc = %d\n", process->pc);
    printf("alive = %d\n", process->alive);
    printf("next = %p\n", process->next);
    printf("previous = %p\n", process->previous);
    printf("-------------\n");
}

void print_vm(t_vm *vm)
{
    printf("---VM---\n");
    printf("nbprocess = %d\n", vm->stack.nbprocess);
    printf("nbplayers = %d\n", vm->nbplayers);
    printf("cycle= %d\n", vm->cycle);
    printf("check_cycles = %d\n", vm->check_cycles);
    printf("cycle_die = %d\n", vm->cycle_die);
    printf("pause = %d\n", vm->pause);
    printf("nb_lives = %d\n", vm->nb_lives);
    printf("checks = %d\n", vm->checks);
    printf("--------\n");
}