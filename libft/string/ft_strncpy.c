/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:44:28 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 10:46:30 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (len)
	{
		dst[n] = src[i];
		if (src[i])
			i++;
		else
			dst[n] = '\0';
		n++;
		len--;
	}
	return (dst);
}
