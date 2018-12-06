/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:09:42 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:50:57 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*cpy;

	tmp = (char*)dest;
	cpy = (const char*)src;
	while (n--)
	{
		*tmp = *cpy;
		tmp++;
		cpy++;
	}
	return (dest);
}
