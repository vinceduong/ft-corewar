/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:06:35 by vduong            #+#    #+#             */
/*   Updated: 2018/11/30 10:46:00 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		delete_process(t_stack *stack, t_proc *process)
{
    t_proc *previous;
    t_proc *next;

    if (stack->start == process)
    {
        stack->start = process->next;
        if (process->next)
            stack->start->previous = NULL;
    }
    else
    {
        previous = process->previous;
        next = process->next;
        previous->next = next;
        if (next)
            next->previous = previous;
        else
            stack->end = previous;
    }
    stack->nbprocess--;
    free(process);
}
