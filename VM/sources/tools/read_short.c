/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:09:19 by afourcad          #+#    #+#             */
/*   Updated: 2018/12/01 13:27:33 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

short	read_short(t_case ram[MEM_SIZE], int pc)
{
	char	tab[2];

	tab[0] = ram[(pc + 1) % MEM_SIZE].content;
	tab[1] = ram[pc].content;
	return (*((short*)tab));
}
