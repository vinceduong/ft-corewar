/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:42:36 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/16 18:08:48 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int swap_int(int n)
{
	return (((n & 0x000000ff) << 24)
		| ((n & 0x0000ff00) << 8)
		| ((n & 0x00ff0000) >> 8)
		| ((n & 0xff000000) >> 24));
}

unsigned int swap_uint(unsigned int n)
{
	return (((n & 0x000000ff) << 24)
		| ((n & 0x0000ff00) << 8)
		| ((n & 0x00ff0000) >> 8)
		| ((n & 0xff000000) >> 24));
}