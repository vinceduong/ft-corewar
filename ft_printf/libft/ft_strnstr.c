/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:16:32 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:53:27 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (len == 0)
		return (0);
	while (haystack[a] != '\0' && a < len)
	{
		b = 0;
		while (haystack[a + b] == needle[b] && (a + b) < len && needle[b])
			b++;
		if (needle[b] == '\0')
			return ((char*)&haystack[a]);
		a++;
	}
	return (0);
}
