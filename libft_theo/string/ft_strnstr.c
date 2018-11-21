/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:13:17 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 10:46:41 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int l;

	i = -1;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] && len > 0)
	{
		l = len;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && haystack[i + j] && l != 0)
			{
				j++;
				l--;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			j = 0;
		}
		len--;
	}
	return (NULL);
}
