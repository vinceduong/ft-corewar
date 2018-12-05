/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:35 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/05 01:58:09 by tescriva         ###   ########.fr       */
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

typedef struct s_operation
{
	char			*name;
	char			*p[3];
	int				param[3];
	int				t_arg[3];
	int				value[3];
	int				nb_param;
	int				id;
}				t_operation;

typedef struct s_lab
{
	char	*name;
	int		n;
	int		i;
	int		num;
}			t_lab;

typedef struct	s_asm
{
	t_lab *l;
	t_operation ope;
	int label;
	int			*part;
	int			fd;
	int			name;
	int			comment;
	unsigned int			magic;
	int			instruction;
	char		**content;
	char		*filename;
	char		**tab;
	int			ope_size;
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
int ft_labchar(char c);
void ft_ope_arg(char *str, t_asm *f);
void ft_test_arg(t_asm *f);

#endif
