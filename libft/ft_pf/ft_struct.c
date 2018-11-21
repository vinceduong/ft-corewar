/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 11:42:26 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 12:02:29 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	pf_pustr(char *s, int i)
{
	write(1, s, i);
}

int		ft_display(t_arg *pf)
{
	int i;

	i = pf->ret;
	if (pf->ret == -2)
		write(1, "for real ?", 10);
	if (pf->ret == -1)
	{
		pf->buf[pf->indextmp] = '\0';
		pf_pustr(pf->buf, pf->indextmp);
		ft_reset_flag(pf);
		free(pf);
		pf = NULL;
		return (i);
	}
	else
	{
		pf->buf[pf->index] = '\0';
		i += pf->ret == pf->index ? 0 : pf->index;
		pf_pustr(pf->buf, pf->index);
		free(pf);
		pf = NULL;
	}
	return (i);
}

void	ft_reset_flag(t_arg *pf)
{
	ft_bzero(pf->flag, 13);
	pf->width = -1;
	pf->wipr = -1;
	pf->arg = 0;
}

void	ft_pf_copy(char c, t_arg *pf)
{
	if (pf->ret == -1)
		return ;
	pf->buf[pf->index++] = c;
	if (pf->index == 4096)
	{
		pf_pustr(pf->buf, pf->index);
		ft_bzero(pf->buf, 4096);
		pf->ret += pf->index;
		pf->index = 0;
	}
}

t_arg	*ft_init(t_arg *pf)
{
	pf = (t_arg*)malloc(sizeof(t_arg));
	ft_bzero((void*)pf, sizeof(t_arg));
	pf->width = -1;
	pf->wipr = -1;
	ft_bzero(pf->flag, 12);
	pf->buf[4095] = '\0';
	return (pf);
}
