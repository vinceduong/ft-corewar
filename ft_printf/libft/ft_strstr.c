/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:17:24 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:53:37 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *src, const char *find)
{
	size_t	len;

	len = ft_strlen(find);
	if (*find == '\0' || !find)
		return ((char *)src);
	while (*src)
	{
		if (ft_strncmp(src, find, len) == 0)
			return ((char *)src);
		src++;
	}
	return (NULL);
}
