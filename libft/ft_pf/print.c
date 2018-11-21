/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:16:15 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 12:02:35 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print(va_list ag, t_arg *pf)
{
	if (pf->arg == 'd' || pf->arg == 'u')
		pf->arg == 'd' ? ft_print_d(ag, pf) : ft_print_unsigned(ag, pf);
	else if (pf->arg == 'x' || pf->arg == 'X' || pf->arg == 'p')
		pf->arg == 'x' || pf->arg == 'p' ? ft_print_x(ag, pf)
		: ft_print_bigx(ag, pf);
	else if (pf->arg == 'c' || pf->arg == 's'
	|| pf->arg == 'C' || pf->arg == 'S')
		pf->arg == 'c' || pf->arg == 'C' ?
		ft_print_c(ag, pf) : ft_print_s(ag, pf);
	else if (pf->arg == '%' || pf->arg == 'o')
		pf->arg == 'o' ? ft_print_o(ag, pf) : ft_print_percent(pf);
	else
	{
		pf->width--;
		!pf->flag[2] ? ft_handle_flag(2, pf, 0, 0) : 0;
		ft_pf_copy(pf->arg, pf);
		if (pf->flag[2])
		{
			while (pf->width-- > 0)
				ft_pf_copy(' ', pf);
		}
	}
}
