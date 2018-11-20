/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:13 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 20:41:22 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void add(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)vm;
	proc->r[ope->param[2]] = (proc->r[ope->param[1]] + proc->r[ope->param[0]]);
	proc->carry = !proc->r[ope->param[2]] ? 1 : 0;
}
