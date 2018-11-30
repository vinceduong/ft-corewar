/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:32 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/30 15:35:37 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		sub(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)vm;

	//ft_putstr("In sub\n");
	proc->r[ope->param[2] - 1] = proc->r[ope->param[0] - 1] - proc->r[ope->param[1] - 1];
	proc->carry = !proc->r[ope->param[2] - 1] ? 1 : 0;
}
