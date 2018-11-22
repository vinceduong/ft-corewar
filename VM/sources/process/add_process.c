/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:02:08 by vduong            #+#    #+#             */
/*   Updated: 2018/11/22 14:26:47 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void add_process(t_stack *stack, t_proc *process)
{
    t_proc *tmp;

    tmp = stack->start;
    if (!tmp)
    {
        stack->start = process;
		stack->nbprocess++;
        return ;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = process;
    process->previous = tmp;
    process->next = NULL;
    stack->end = process;
    stack->nbprocess++;
}
