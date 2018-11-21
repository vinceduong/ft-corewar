/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:18:03 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:26:50 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoinfree(char *s1, const char *s2)
{
	char *dst;

	dst = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (dst);
}
