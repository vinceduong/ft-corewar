/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:02:08 by vduong            #+#    #+#             */
/*   Updated: 2018/11/20 12:16:19 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void add_process(t_stack *stack, t_proc *proc)
{
    t_proc *tmp;

    tmp = stack->start;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = proc;
    proc->previous = tmp;
    proc->next = NULL;
    stack->nbprocess++;
}