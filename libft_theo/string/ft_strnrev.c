/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:50:55 by tescriva          #+#    #+#             */
/*   Updated: 2018/09/25 10:46:38 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnrev(const char *src, size_t n)
{
	int		i;
	int		j;
	char	*dst;

	i = ft_strlen(src);
	j = 0;
	dst = (char*)malloc(sizeof(char) * i + 1);
	if (!dst)
		return (NULL);
	while (i != 0 && n-- >= 1)
	{
		i--;
		dst[j] = src[i];
		j++;
	}
	return (dst);
}
