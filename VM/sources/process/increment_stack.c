/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:00:57 by vduong            #+#    #+#             */
/*   Updated: 2018/11/25 13:25:28 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	increment_stack(t_vm *vm)
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
            execute_process(vm, tmp);
        }
        tmp = tmp->previous;
    }
}
