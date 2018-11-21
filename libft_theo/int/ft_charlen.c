/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:24:07 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:24:52 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_charlen(wchar_t c)
{
	if ((0xD800 <= c && c <= 0xDFFF) || c < 0 || c > 0x10FFFF)
		return (-1);
	if (c > 0xFFFF)
		return (4);
	else if (c > 0x7FF)
		return (3);
	else if ((c > 0x7F && MB_CUR_MAX >= 2) || c > 0xFF)
		return (2);
	else
		return (1);
}
