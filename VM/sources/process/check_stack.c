/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:18:42 by vduong            #+#    #+#             */
/*   Updated: 2018/11/28 16:40:30 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_stack(t_vm *vm)
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
            delete_process(&vm->stack, tmp);
        tmp = next;
    }
	//print_vm(vm);
	//printf("coucou %d\n", vm->die_rounds_left);
    if (vm->lives >= NBR_LIVE || --vm->die_rounds_left <= 0)
	{
		vm->cycles_to_die = vm->cycles_to_die > CYCLE_DELTA ?
			vm->cycles_to_die - CYCLE_DELTA : 1;
		vm->die_rounds_left = MAX_CHECKS;
	}
	//print_vm(vm);
	vm->cycles_left = vm->cycles_to_die;
	vm->lives = 0;
	return (vm->stack.start != NULL ? 1 : 0);
}
