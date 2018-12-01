/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2018/12/01 13:40:49 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		handle_processes(t_vm *vm)
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
	while (1)
	{
		vm->sbs = 0;
		//dump_ram(vm);
		if (vm->cycles_total == vm->dump_cycle && !vm->visu)
			dump_ram(vm);
		vm->cycles_total++;
		handle_processes(vm);
		vm->cycles_left--;
		if (!vm->cycles_left && !check_processes(vm))
			break ;
	}
	vm->win = 1;
	printf("Total cycles = %d\n", vm->cycles_total);
	dump_ram(vm);
}
