/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:19:52 by vduong            #+#    #+#             */
/*   Updated: 2018/11/24 09:26:43 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void print_process(t_proc *process)
{
   // printf("---PROCESS---\n");
   // printf("registres = [%d][%d][%d][%d]\n", process->r[0],process->r[1],process->r[2],process->r[3]);
   // printf("id = %d\n", process->id);
  //  printf("carry = %d\n", process->carry);
    //printf("player = %d\n", process->player);
   // printf("opcode = %#x\n", process->opcode);
   // printf("cycle = %d\n", process->cycle);
   // printf("pc = %d\n", process->pc);
   // printf("alive = %d\n", process->alive);
   // printf("current = %p\n", process);
   // printf("next = %p\n", process->next);
   // printf("previous = %p\n", process->previous);
   // printf("-------------\n");
}

void print_vm(t_vm *vm)
{
  /*  printf("---VM---\n");
    printf("nbprocess = %d\n", vm->stack.nbprocess);
    printf("nbplayers = %d\n", vm->nbplayers);
    printf("cycle= %d\n", vm->cycles_total);
    printf("check_cycles = %d\n", vm->cycles_left);
    printf("cycle_die = %d\n", vm->cycles_to_die);
    printf("pause = %d\n", vm->pause);
    printf("nb_lives = %d\n", vm->lives);
    printf("checks = %d\n", vm->die_rounds_left);
    printf("--------\n");*/
}

void print_stack(t_stack stack)
{
    t_proc *tmp;

    tmp = stack.start;
    printf("******THE STACK******\n");
    while (tmp)
    {
        print_process(tmp);
        tmp = tmp->next;
    }
    printf("*********************\n");

}