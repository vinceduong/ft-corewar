/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:49:51 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 15:46:37 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		increment_processes(t_vm *vm)
{
	t_proc	*process;

	process = vm->processes;
	while (process)
	{
		if (!process->cycles)
			load_instruction(process, vm);
		process->cycles--;
		if (!process->cycles)
			execute_instruction(process, vm);
		process = process->next;
	}
}

void			loop(t_vm *vm)
{
	if (vm->visu)
    	create_visualizer(vm, &vm->display);
	while (1)
	{
		if (vm->visu)
			display(vm);
		if (vm->cycles_total == vm->dump_cycle && !vm->visu)
			dump_ram(vm);
		vm->cycles_total++;
		if (!vm->visu && vm->show_cycles)
			ft_printf("It is now cycle %d\n", vm->cycles_total);
		//printf("Cycle = %d, Number of processes = %d\n", vm->cycles_total, vm->num_processes);
		increment_processes(vm);
		vm->cycles_left--;
		if (!vm->cycles_left && !check_processes(vm))
			break ;
	}
	vm->win = 1;
//	dump_ram(vm);
}
