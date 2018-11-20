/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:00:57 by vduong            #+#    #+#             */
/*   Updated: 2018/11/20 16:14:29 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void increment_stack(t_vm *vm)
{
    t_proc *tmp;

    tmp = vm->stack.end;
    while (tmp)
    {
        tmp->cycle--;
        if (!tmp->cycle)
            execution(vm, tmp);
        tmp = tmp->previous;
    }
}