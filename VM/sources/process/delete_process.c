/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:06:35 by vduong            #+#    #+#             */
/*   Updated: 2018/11/20 13:00:58 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void delete_process(t_stack *stack, t_proc *process)
{
    t_proc *tmp;

    tmp = stack->start;
    if (tmp == process)
    {
        stack->start = tmp->next;
        stack->start->previous = NULL;
    }
    else
    {
        while (tmp->next != process)
            tmp = tmp->next;
        tmp->next = process->next;
        if (process->next)
            process->next->previous = tmp;
    }
    stack->nbprocess--;*
    free(process);
}