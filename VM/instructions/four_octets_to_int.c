/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_octets_to_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:45:56 by afourcad          #+#    #+#             */
/*   Updated: 2018/11/30 18:03:58 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	four_octets_to_int(unsigned char ram[MEM_SIZE], int pc)
{
	char	tab[4];

	tab[0] = ram[(pc + 3) % MEM_SIZE];
	tab[1] = ram[(pc + 2) % MEM_SIZE];
	tab[2] = ram[(pc + 1) % MEM_SIZE];
	tab[3] = ram[pc];
	return (*((int*)tab));
}
