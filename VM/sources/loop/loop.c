/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:33:41 by vduong            #+#    #+#             */
/*   Updated: 2018/11/22 14:19:15 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void loop(t_vm *vm)
{
    int step;

    step = 1;
    while (1)
    {
        if (vm->flag.visu)
            /*display(vm, step)*/;
        else if (vm->cycle == vm->flag.dump)
            dump(vm);
        vm->cycle++;
        increment_stack(vm);
        vm->check_cycles--;
        if (!vm->check_cycles && !check_stack(vm))
            break;
        step = 2;
    }
    printf("J'ai fait %d cycles \nJe suis a %d cycle_to_die\n", vm->cycle, vm->cycle_die);
}
