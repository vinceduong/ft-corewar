/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:50:38 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/04 17:18:55 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

ft_get_operation(t_asm *f)
{
	int n;
	int opcode;

	n = f->x;
	while (f->tab[n])
	{
		opcode = 0;
	}
}

void ft_program(t_asm *f)
{
	t_header e;

	ft_get_operation(f);
	f->fd = open(f->filename, O_CREAT | O_WRONLY | O_TRUNC
		| S_IRUSR | S_IWUSR);
	if (f->fd == -1)
		error("can't create file");
	ft_bzero(&e, sizeof(e));
	e.magic = swap_uint(COREWAR_EXEC_MAGIC);
	ft_strcpy(e.prog_name, f->content[NAME]);
	ft_strcpy(e.comment, f->content[COMMENT]);
	write(f->fd, &e, sizeof(e));
}
