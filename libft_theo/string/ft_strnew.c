/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:04:04 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 10:46:35 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnew(size_t t)
{
	char *str;

	str = (char *)malloc(sizeof(char) * t + 1);
	if (str == NULL)
		return (NULL);
	if (!t)
		return (str);
	ft_bzero(str, t + 1);
	return (str);
}
