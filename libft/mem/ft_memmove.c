/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:35:36 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 10:44:54 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!len || dest == src)
		return (dest);
	else if (dest <= src)
		ft_memcpy(dest, src, len);
	else
	{
		while ((long long)--len >= 0)
			*((char *)dest + len) = *((char *)src + len);
	}
	return (dest);
}
