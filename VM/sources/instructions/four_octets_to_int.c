/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_octets_to_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:45:56 by afourcad          #+#    #+#             */
/*   Updated: 2018/12/01 12:03:17 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	four_octets_to_int(t_case ram[MEM_SIZE], int pc)
{
	char	tab[4];

	tab[0] = ram[(pc + 3) % MEM_SIZE].content;
	tab[1] = ram[(pc + 2) % MEM_SIZE].content;
	tab[2] = ram[(pc + 1) % MEM_SIZE].content;
	tab[3] = ram[pc].content;
	return (*((int*)tab));
}
