/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:27:09 by tescriva          #+#    #+#             */
/*   Updated: 2018/09/25 10:46:47 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrev(const char *src)
{
	int		i;
	int		n;
	char	*dst;

	i = ft_strlen(src);
	n = 0;
	dst = (char*)malloc(sizeof(char) * i + 1);
	if (!dst)
		return (NULL);
	dst[i] = '\0';
	while (i != 0)
	{
		i--;
		dst[n] = src[i];
		n++;
	}
	return (dst);
}
