/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:17:44 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:53:41 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!str || !s)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[i] = s[start + i];
		i++;
	}
	return (&str[0]);
}
