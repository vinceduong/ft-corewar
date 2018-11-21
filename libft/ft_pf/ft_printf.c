/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 11:35:15 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/26 10:21:34 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_start(va_list ag, t_arg *pf, const char *format)
{
	int		i;

	i = -1;
	while (format[++i])
	{
		while (format[i] == '%')
		{
			i += ft_get_arg(ag, pf, format + i);
			ft_reset_flag(pf);
			pf->ret == -1 ? 0 : (pf->indextmp = pf->index);
		}
		if (format[i] == '\0')
			break ;
		if (pf->ret == -1)
			break ;
		format[i] != '%' ? ft_pf_copy(format[i], pf) : 0;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		ag;
	t_arg		*pf;

	pf = NULL;
	pf = ft_init(pf);
	va_start(ag, format);
	ft_start(ag, pf, format);
	va_end(ag);
	return (ft_display(pf));
}
