/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:33:41 by vduong            #+#    #+#             */
/*   Updated: 2018/11/29 15:37:47 by vduong           ###   ########.fr       */
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
<<<<<<< HEAD
	dump(vm);
    printf("J'ai fait %d cycles \nJe suis a %d cycle_to_die\n", vm->cycles_total, vm->cycles_to_die);
=======
    if (vm->flag.visu)
        display_winner(&vm->display);
	//dump(vm);
  //  printf("J'ai fait %d cycles \nJe suis a %d cycle_to_die\n", vm->cycles_total, vm->cycles_to_die);
>>>>>>> visu
}
