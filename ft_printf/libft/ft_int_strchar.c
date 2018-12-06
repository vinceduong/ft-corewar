/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:47:50 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:47:50 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_strchar(const char *src, const char find)
{
	while (*src)
	{
		if (*src == find)
			return (1);
		src++;
	}
	return (0);
}
