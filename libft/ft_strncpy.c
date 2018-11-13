/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:50:46 by vduong            #+#    #+#             */
/*   Updated: 2017/11/17 14:50:47 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *tmp;

	tmp = (char *)dest;
	while (n)
	{
		if (*src)
			*tmp++ = *src++;
		else
			*tmp++ = '\0';
		n--;
	}
	return (dest);
}
