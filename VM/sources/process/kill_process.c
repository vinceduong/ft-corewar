/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:16:26 by vduong            #+#    #+#             */
/*   Updated: 2018/12/01 14:16:26 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	kill_process(t_proc *process, t_vm *vm)
{
	t_proc	**prev_next;

	if (vm->visu && vm->viewed_process == process)
		vm->viewed_process = vm->viewed_process->next;
	prev_next = &vm->processes;
	while (*prev_next != process)
		prev_next = &(*prev_next)->next;
	*prev_next = process->next;
	free(process);
	vm->num_processes--;
}