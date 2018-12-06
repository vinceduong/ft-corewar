/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:15:59 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 14:52:34 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	create_process(t_vm *vm, int pc, int player_num, int no_init)
{
	static int	id = 1;
	t_proc		*process;

	process = (t_proc*)malloc(sizeof(t_proc));
	if (!process)
		exit(1);
	vm->num_processes++;
	vm->proc_created = id;
	process->next = vm->processes;
	process->last_cycle_alive = vm->cycles_total;
	process->previous = NULL;
	if (vm->processes)
		vm->processes->previous = process;
	vm->processes = process;
	process->id = id++;
	process->pc = pc;
	load_instruction(process, vm);
	if (no_init)
		return ;
	process->alive = 0;
	process->r[0] = player_num;
	ft_bzero(&process->r[1], (REG_NUMBER - 1) * sizeof(int));
	process->carry = 0;
}