/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:16:26 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 15:59:59 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	kill_process(t_proc *process, t_vm *vm)
{
	t_proc *next;
	t_proc *previous;

	if (!vm->visu && vm->show_deaths)
	{
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
		process->id, vm->cycles_total - process->last_cycle_alive,
		vm->cycles_to_die, vm->cycles_total);

	}
	if (vm->processes == process)
		vm->processes = process->next;
	next = process->next;
	previous = process->previous;
	if (next)
		next->previous = process->previous;
	if (previous)
		previous->next = process->next;	
	free(process);
	vm->num_processes--;
}