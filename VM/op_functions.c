/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:27:01 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/11 17:44:26 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	(*g_op_functions[16])(t_vm*, t_proc*, t_instruction*) =
{
	live,
	direct_load,
	direct_store,
	add,
	sub,
	cor_and,
	cor_or,
	cor_xor,
	zjmp,
	indirect_load,
	indirect_store,
	cor_fork,
	long_direct_load,
	long_indirect_load,
	cor_lfork,
	aff,
};
