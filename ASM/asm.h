/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:35 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/03 16:54:40 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

#include "op.h"
#include "libft.h"

#define ASM_H
#define MAGIC 0
#define NAME 1
#define COMMENT_LENGTH 2
#define OPE 3

typedef struct	s_asm
{
	int			*part;
	int			name;
	int			comment;
	int			instruction;
	int			**label;
	char		**content;
	char		**tab;
	int			error;
	int			x;
	int			y;
}				t_asm;

void			ft_get_comment(f);
void			ft_get_comment(f);

#endif
