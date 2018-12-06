/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:48:14 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:48:14 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_strstr(const char *src, const char *find)
{
	size_t	len;

	len = ft_strlen(find);
	if (*find == '\0' || !find)
		return (0);
	while (*src)
	{
		if (ft_strncmp(src, find, len) == 0)
			return (1);
		src++;
	}
	return (0);
}
