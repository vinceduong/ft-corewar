/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:18:42 by vduong            #+#    #+#             */
/*   Updated: 2018/11/23 18:24:58 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int check_stack(t_vm *vm)
{
    t_proc *tmp;
    t_proc *next;

    tmp = vm->stack.start;
    print_vm(vm);
    //print_stack(vm->stack);
    while (tmp)
    {
        next = tmp->next;
        if (tmp->alive)
            tmp->alive = 0;
        else
        {
            //printf("need to delete->");
            delete_process(&vm->stack, tmp);
          	//printf("deleted\n");
        }
        tmp = next;
    }
	//print_vm(vm);
	//printf("coucou %d\n", vm->checks);
    if (vm->nb_lives >= NBR_LIVE || --vm->checks <= 0)
	{
		vm->cycle_die = vm->cycle_die > CYCLE_DELTA ?
			vm->cycle_die - CYCLE_DELTA : 1;
		vm->checks = MAX_CHECKS;
	}
	//print_vm(vm);
	vm->check_cycles = vm->cycle_die;
	vm->nb_lives = 0;
	return (vm->stack.start != NULL);
}
