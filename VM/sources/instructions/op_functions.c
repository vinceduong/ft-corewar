/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:54:58 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 10:54:59 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	(*g_op_functions[16])(t_vm*, t_proc*, t_instruction*) =
{
	live,
	direct_load,
	direct_store,
	add,
	sub,
	log_and,
	log_or,
	log_xor,
	zjmp,
	indirect_load,
	indirect_store,
	proc_fork,
	long_direct_load,
	long_indirect_load,
	proc_lfork,
	aff,
};
