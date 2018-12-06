/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:15:16 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:52:36 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	size;
	int		i;

	if (s && f)
	{
		i = 0;
		size = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (size + 1));
		if (str)
		{
			str[size] = '\0';
			while (s[i])
			{
				str[i] = (*f)(s[i]);
				i++;
			}
			return (&str[0]);
		}
		return (NULL);
	}
	return (NULL);
}
