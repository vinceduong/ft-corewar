/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:35 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/06 18:34:32 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

#define ASM_H
#include "../VM/includes/op.h"
#include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

#define NAME 0
#define COMMENT 1

typedef struct		s_operation
{
	char			*name;
	char			*p[3];
	int				param[3];
	int				t_arg[3];
	int				value[3];
	int				nb_param;
	int				id;
}					t_operation;

typedef struct		s_lab
{
	char			*name;
	int				n;
	int				i;
	int				num;
}					t_lab;

typedef struct		s_asm
{
	t_lab			*l;
	t_operation		ope;
	char			**content;
	char			*filename;
	char			**tab;
	int				label;
	int				*part;
	int				fd;
	int				name;
	int				comment;
	int				num;
	int				instruction;
	int				ope_size;
	int				no_error;
	int				test;
	int				x;
	int				y;
}					t_asm;

char				*ft_strjoinfree(char *s1, char *s2);
int					ft_check_file(t_asm *f, char *str);
int					ft_labchar(char c);
int					swap_int(int n);
short				swap_short(short n);
unsigned int		swap_uint(unsigned int n);
void				ft_get_length(t_asm *f, char *name, char *comment);
void				error(char *str);
void				ft_start(t_asm *f, char **av, int ac);
void				error(char *str);
void				ft_program(t_asm *f);
void				malloc_size(t_asm *f);
void				ft_file_is_valid(t_asm *f, int fd);
void				ft_ope_arg(char *str, t_asm *f);
void				ft_test_arg(t_asm *f);
void				ft_write_prog(t_asm *f);




#endif
