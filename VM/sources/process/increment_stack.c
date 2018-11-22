/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:00:57 by vduong            #+#    #+#             */
/*   Updated: 2018/11/21 20:05:11 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void increment_stack(t_vm *vm)
{
    t_proc *tmp;

    tmp = vm->stack.end;
    while (tmp)
    {
        if (!tmp->cycle)
            load_next_instruction(vm, tmp);
        tmp->cycle--;
        if (!tmp->cycle)
        {
            //print_vm(vm);
            //print_process(tmp);
            execution(vm, tmp);
        }
        tmp = tmp->previous;
    }
}
