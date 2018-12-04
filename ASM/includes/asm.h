/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:35 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/04 16:19:14 by thescriv         ###   ########.fr       */
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

#define NAME 0
#define COMMENT 1
#define OPE 2

typedef struct	s_asm
{
	int			*part;
	int			fd;
	int			name;
	int			comment;
	unsigned int			magic;
	int			instruction;
	int			**label;
	char		**content;
	char		*filename;
	char		**tab;
	int			error;
	int			x;
	int			y;
}				t_asm;

void			ft_get_length(t_asm *f, char *name, char *comment);
char			*ft_strjoinfree(char *s1, char *s2);
int ft_check_file(t_asm *f, char *str);
void			error(char *str);
void			free_the_whole_word(t_asm *f);
void			ft_start(t_asm *f, char **av, int ac);
void			error(char *str);
void ft_program(t_asm *f);
void malloc_size(t_asm *f);
void ft_file_is_valid(t_asm *f, int fd);
unsigned int	swap_uint(unsigned int n);

#endif
