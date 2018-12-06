/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:13:44 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:52:50 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strndup(const char *s, int n)
{
	const char	*str;
	char		*dup;
	int			i;
	int			len;

	str = (const char *)s;
	len = ft_strlen(str);
	len = (len > n) ? n : len;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!dup)
		return (NULL);
	while (i < len && str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
