/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:06:35 by vduong            #+#    #+#             */
/*   Updated: 2018/11/25 13:25:24 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		delete_process(t_stack *stack, t_proc *process)
{
    t_proc *tmp;

    tmp = stack->start;
    if (tmp == process)
    {
        stack->start = tmp->next;
        if (tmp->next)
            stack->start->previous = NULL;
    }
    else
    {
        while (tmp->next != process)
            tmp = tmp->next;
        tmp->next = process->next;
        if (process->next)
            process->next->previous = tmp;
        else
            stack->end = tmp;
    }
    stack->nbprocess--;
    free(process);
}
