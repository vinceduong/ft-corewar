/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:07:59 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:50:51 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	while (len--)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		else
			tmp++;
	}
	return (NULL);
}
