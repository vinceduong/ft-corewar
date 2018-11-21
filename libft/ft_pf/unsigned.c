/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:06:37 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:23:35 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_del(char **as)
{
	free(*as);
	*as = NULL;
}

void	ft_print_unsigned(va_list ag, t_arg *pf)
{
	uintmax_t	nb;
	char		*n;
	int			i;
	int			j;
	char		*temp;

	i = pf->width;
	j = pf->wipr;
	n = NULL;
	nb = ft_cast_unsigned(ag, pf);
	ft_handle_flag(1, pf, ft_intlen_unsigned(nb, 10), nb == 0 ? 0 : 1);
	if (nb == 0 && i <= -1 && j <= -1 && pf->flag[3] == '.')
		return ;
	n = ft_pf_itoa_base(nb, DEC, 10);
	temp = n;
	while (n != NULL && *n)
		ft_pf_copy(*n++, pf);
	if (pf->flag[2] && pf->width > 0)
	{
		while (pf->width--)
			ft_pf_copy(' ', pf);
	}
	n == NULL ? pf->ret = -1 : 0;
	pf->ret == -1 ? 0 : ft_del(&temp);
}

void	ft_print_bigx(va_list ag, t_arg *pf)
{
	uintmax_t	nb;
	char		*n;
	int			i;
	int			j;

	i = pf->width;
	j = pf->width;
	nb = ft_cast_unsigned(ag, pf);
	nb == 0 && pf->flag[0] == '#' ? pf->flag[0] = 0 : 0;
	ft_handle_flag(1, pf, ft_intlen_unsigned(nb, 16), nb == 0 ? 0 : 1);
	if (nb == 0 && i <= -1 && j <= -1 && pf->flag[3] == '.')
		return ;
	i = -1;
	n = ft_pf_itoa_base(nb, "0123456789ABCDEF", 16);
	while (n[++i])
		ft_pf_copy(n[i], pf);
	if (pf->flag[2] && pf->width > 0)
	{
		while (pf->width--)
			ft_pf_copy(' ', pf);
	}
	free(n);
}

void	ft_print_x(va_list ag, t_arg *pf)
{
	uintmax_t	nb;
	char		*n;
	int			i;
	int			j;

	i = pf->width;
	j = pf->wipr;
	nb = ft_cast_unsigned(ag, pf);
	nb == 0 && pf->arg != 'p' ? pf->flag[0] = 0 : 0;
	nb == 0 && !pf->flag[0] && !pf->flag[3] ? pf->width++ : 0;
	ft_handle_flag(1, pf, ft_intlen_unsigned(nb, 16), nb == 0 ? 0 : 1);
	if (nb == 0 && j <= 0 && pf->flag[3] == '.')
		return ;
	i = -1;
	n = ft_pf_itoa_base(nb, "0123456789abcdef", 16);
	while (n[++i])
		ft_pf_copy(n[i], pf);
	if (pf->flag[2] && pf->width > 0)
	{
		while (pf->width--)
			ft_pf_copy(' ', pf);
	}
	free(n);
}

void	ft_print_o(va_list ag, t_arg *pf)
{
	uintmax_t	nb;
	char		*n;
	int			i;
	int			j;

	i = pf->width;
	j = pf->wipr;
	nb = ft_cast_unsigned(ag, pf);
	pf->flag[0] && pf->flag[3] && nb == 0 && pf->width <= 1 && pf->wipr <= 1
	? ft_pf_copy('0', pf) : 0;
	nb == 0 ? pf->flag[0] = 0 : 0;
	nb == 0 && pf->flag[0] == '#' ? pf->flag[3] = 0 : 0;
	ft_handle_flag(1, pf, ft_intlen_unsigned(nb, 8), nb == 0 ? 0 : 1);
	if (nb == 0 && j <= 1 && pf->flag[3] == '.')
		return ;
	i = -1;
	n = ft_pf_itoa_base(nb, OCTAL, 8);
	while (n[++i])
		ft_pf_copy(n[i], pf);
	if (pf->flag[2] && pf->width > 0)
	{
		while (pf->width--)
			ft_pf_copy(' ', pf);
	}
	free(n);
}
