/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:25:06 by vduong            #+#    #+#             */
/*   Updated: 2018/11/24 11:25:17 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	tab_to_type(char param_types[3], char arg[3])
{
	if (arg[0] == T_REG)
		param_types[0] = REG_CODE;
	else if (arg[0] == T_DIR)
		param_types[0] = DIR_CODE;
	else if (arg[0] == T_IND)
		param_types[0] = IND_CODE;
	else
		param_types[0] = 0;
	if (arg[1] == T_REG)
		param_types[1] = REG_CODE;
	else if (arg[1] == T_DIR)
		param_types[1] = DIR_CODE;
	else if (arg[1] == T_IND)
		param_types[1] = IND_CODE;
	else
		param_types[1] = 0;
	if (arg[2] == T_REG)
		param_types[2] = REG_CODE;
	else if (arg[2] == T_DIR)
		param_types[2] = DIR_CODE;
	else if (arg[2] == T_IND)
		param_types[2] = IND_CODE;
	else
		param_types[2] = 0;
}