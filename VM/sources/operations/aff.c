/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:10 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 20:04:59 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void aff(t_vm *vm, t_proc *proc, t_operation *operation)
{
	char c;

	c = proc->r[ope->param[0]] % 256
	ft_putchar(c);
	proc->carry = c == 0 ? 1 : 0;
}
