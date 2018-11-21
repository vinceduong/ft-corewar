/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:06:27 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:20:56 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_percent(t_arg *pf)
{
	pf->width--;
	pf->wipr--;
	if (pf->flag[2] != '-')
	{
		if (pf->flag[1] == '0' || pf->flag[3])
		{
			while (pf->width-- > 0)
				ft_pf_copy('0', pf);
		}
		else
			while (pf->width-- > 0)
				ft_pf_copy(' ', pf);
	}
	ft_pf_copy('%', pf);
	if (pf->flag[2] == '-')
	{
		while (pf->width--)
			ft_pf_copy(' ', pf);
	}
}
