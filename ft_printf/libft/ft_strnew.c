/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:16:22 by apoque            #+#    #+#             */
/*   Updated: 2018/12/06 12:53:25 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}
