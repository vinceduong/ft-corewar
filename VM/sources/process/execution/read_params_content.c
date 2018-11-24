/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:28:34 by vduong            #+#    #+#             */
/*   Updated: 2018/11/24 11:28:45 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void read_params_content(t_operation *ope, int n, t_vm *vm, int *pc)
{
	if (!ope->param_type[n])
		return ;
	if (ope->param_type[n] == REG_CODE)
	{
		ope->param[n] = vm->ram[*pc].content;
		if (ope->param[n] < 1 || ope->param[n] > REG_NUMBER)
			ope->error = 1;
		*pc = mod_pc(*pc + 1);
	}
	else if (ope->param_type[n] == IND_CODE || op_tab[ope->opcode - 1].d2)
	{
		ope->param[n] = read_short(vm, *pc);
		*pc = mod_pc(*pc + 2);
	}
	else if (ope->param_type[n] == DIR_CODE)
	{
		ope->param[n] = read_int(vm, *pc);
		*pc = mod_pc(*pc + 4);
	}
}