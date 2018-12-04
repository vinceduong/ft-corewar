/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_static_params_types.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:43:15 by vduong            #+#    #+#             */
/*   Updated: 2018/12/01 14:10:35 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_static_params_types(char params_types[3], char arg[3])
{
	if (arg[0] == T_REG)
		params_types[0] = REG_CODE;
	else if (arg[0] == T_DIR)
		params_types[0] = DIR_CODE;
	else if (arg[0] == T_IND)
		params_types[0] = IND_CODE;
	else
		params_types[0] = 0;
	if (arg[1] == T_REG)
		params_types[1] = REG_CODE;
	else if (arg[1] == T_DIR)
		params_types[1] = DIR_CODE;
	else if (arg[1] == T_IND)
		params_types[1] = IND_CODE;
	else
		params_types[1] = 0;
	if (arg[2] == T_REG)
		params_types[2] = REG_CODE;
	else if (arg[2] == T_DIR)
		params_types[2] = DIR_CODE;
	else if (arg[2] == T_IND)
		params_types[2] = IND_CODE;
	else
		params_types[2] = 0;
}