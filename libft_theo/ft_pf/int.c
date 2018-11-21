/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:06:07 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:22:37 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_d(va_list ag, t_arg *pf)
{
	intmax_t	nb;
	char		*n;
	int			i;
	int			j;

	j = pf->wipr;
	nb = ft_cast_d(ag, pf);
	ft_handle_flag((nb < 0 ? 0 : 1), pf, ft_intlen(nb), nb == 0 ? 0 : 1);
	if (nb == 0 && j <= -1 && pf->flag[3] == '.')
		return ;
	i = -1;
	n = (unsigned int)nb < sizeof(int)
		? ft_pf_itoa_base((uintmax_t)nb, DEC, 10) : ft_pf_itoa(nb);
	n == NULL ? pf->ret = -1 : 0;
	if (n == NULL)
		return ;
	while (n[++i])
		ft_pf_copy(n[i], pf);
	if (pf->flag[2] && pf->width > 0)
	{
		while (pf->width--)
			ft_pf_copy(' ', pf);
	}
	ft_strdel(&n);
}
