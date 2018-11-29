/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/29 13:08:18 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	zjump(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)vm;
	if (proc->carry == 1)
		proc->pc = mod_pc(proc->pc + (ope->param[0] % IDX_MOD));
}
