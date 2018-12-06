/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:16:01 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:52:48 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*tmp;

	tmp = (char *)dest;
	while (len)
	{
		if (*src)
			*tmp++ = *src++;
		else
			*tmp++ = '\0';
		len--;
	}
	return (dest);
}
