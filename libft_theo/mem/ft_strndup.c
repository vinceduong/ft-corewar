/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:12:23 by tescriva          #+#    #+#             */
/*   Updated: 2018/10/04 11:22:33 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strndup(const char *s1, size_t size)
{
	char		*dest;
	size_t		i;

	i = 0;
	dest = (char*)malloc(sizeof(char*) * size + 1);
	if (!dest)
		return (NULL);
	while (i++ < size)
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}
