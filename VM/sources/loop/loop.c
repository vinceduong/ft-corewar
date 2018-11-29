/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aetchego <aetchego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:33:41 by vduong            #+#    #+#             */
/*   Updated: 2018/11/29 18:28:01 by aetchego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		loop(t_vm *vm)
{
    int step;

    step = 1;
    while (1)
    {
        if (vm->flag.visu)
            display(vm, step);
        //dump(vm);
        vm->cycles_total++;
        //printf("Cycles_total = %d\n", vm->cycles_total);
        increment_stack(vm);
        vm->cycles_left--;
        if (!vm->cycles_left && !check_stack(vm))
            break;
        step++;
    }
    if (vm->flag.visu)
        display_winner(&vm->display);
   // display(vm, step);
	//dump(vm);
  //  printf("J'ai fait %d cycles \nJe suis a %d cycle_to_die\n", vm->cycles_total, vm->cycles_to_die);
}
