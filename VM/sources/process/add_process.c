/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:02:08 by vduong            #+#    #+#             */
/*   Updated: 2018/11/29 15:15:02 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_process(t_stack *stack, t_proc *process)
{
    t_proc *tmp;

    if (!stack->start)
        stack->start = process;
    tmp = stack->end;
    stack->end = process;
    process->previous = tmp;
    if (tmp)
        tmp->next = stack->end;
	stack->nbprocess++;
}
