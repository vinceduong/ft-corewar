/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:20:58 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 10:44:49 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	i = 0;
	if (!n || dst == src)
		return (dst);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	while (n)
	{
		a[i] = b[i];
		i++;
		n--;
	}
	return (dst);
}
