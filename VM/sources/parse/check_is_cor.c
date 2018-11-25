/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:36:24 by vduong            #+#    #+#             */
/*   Updated: 2018/11/25 13:26:21 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_is_cor(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	if (len < 5)
		return (0);
	while (i < len)
	{
		if (str[i] == '.' && len - i == 4)
			return (!ft_strcmp(&str[i], ".cor") ? 1 : 0);
		i++;
	}
	return (0);
}
