/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:35 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/03 17:29:31 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

#define ASM_H
#include "../VM/includes/op.h"
#include "../libft/includes/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

#define MAGIC 0
#define NAME 1
#define COMMENT 2
#define OPE 3

typedef struct	s_asm
{
	int			*part;
	int			name;
	int			comment;
	int			instruction;
	int			**label;
	char		**content;
	char		*filename;
	char		**tab;
	int			error;
	int			x;
	int			y;
}				t_asm;

void			ft_get_name(t_asm *f);
void			ft_get_comment(t_asm *f);
void			error(char *str);

#endif
