/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aetchego <aetchego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:07:31 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/30 18:47:50 by aetchego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <ncurses.h>
# include "libft.h"
# include "op.h"

/*
	live	= 0x01 = 	10 	cycles
	ld		= 0x02 = 	5 	cycles
	st 		= 0x03 =	4 	cycles
	add 	= 0x04 = 	10 	cycles
	sub 	= 0x05 =	10 	cycles
	and 	= 0x06 =	6 	cycles
	or 		= 0x07 =	6 	cycles
	xor 	= 0x08 =	6 	cycles
	zjmp 	= 0x09 = 	20 	cycles
	ldi 	= 0x0a =	25 	cycles
	sti 	= 0x0b =	25 	cycles
	fork 	= 0x0c = 	800 cycles
	lld 	= 0x0d = 	10	cycles
	lldi 	= 0x0e =	50	cycles
	lfork 	= 0x0f =	1000	cycles
	aff 	= 0x10 = 	2	cycles

	NUMBER MAGIC = 0xea83f3 = (0x00) 0xea 0x83 0xf3
*/
#define PHEADER	vm->players[i].header
#define USAGE	"Usage : ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"

typedef struct	s_operation
{
	int			ocp;
	int			opcode;
	int			pc;
	char		param_type[3];
	int 		param[3];
	int			error;
}				t_operation;

typedef struct	s_player
{
	char			*filename;
	int				p;
	int				nb_live;
	unsigned char	prog[CHAMP_MAX_SIZE];
	t_header		*header;
}				t_player;

typedef struct	s_proc
{
	int				r[REG_NUMBER];
	int				id;
	int				carry;
	int				player;
	int				opcode;
	int				cycle;
	int				pc;
	int				cursor;
	int				alive;
	char			*prog;
	struct s_proc	*next;
	struct s_proc	*previous;
}				t_proc;

typedef struct	s_stack
{
	t_proc	*start;
	t_proc	*end;
	int		nbprocess;
}				t_stack;

typedef struct s_flag
{
	int		dump;
	int		n;
	int		visu;
}				t_flag;

typedef struct	s_case
{
	unsigned char	content;
	int				pid;
	int				color;
	int				glow;
}				t_case;

typedef struct	s_win
{
	WINDOW 		*win;
	WINDOW		*win_left;
	WINDOW		*win_right;
	WINDOW		*win_down;
	int			lines;
	int			cols;
	int			name_len;
//	int			speed;
}				t_win;

typedef struct	s_vm
{
	t_case		ram[MEM_SIZE];
	t_stack		stack;
	t_player	players[MAX_PLAYERS];
	t_flag		flag;
	t_win		display;
	int			nbplayers;
	int			winner;
	int			cycles_total;
	int			cycles_left;
	int			cycles_to_die;
	int			die_rounds_left; // checks
	int			pause;
	int			lives;
	int			speed;
}				t_vm;

void	(*ops[16])(t_vm*, t_proc*, t_operation*);

int						ft_printf(const char *format, ...);
/*GENERAL*/
int						swap_int(int n);
unsigned int			swap_uint(unsigned int n);
void					init_vm(t_vm *vm);
void					init_ram(t_vm *vm);
void					error(char *msg);
void					dump(t_vm *vm);

/*PARSING*/
int						parse(t_vm *vm, char **av);
int						check_args(char **av, t_vm *vm);
int						check_is_flag(char **av, int i);
int						check_is_cor(char *str);
int						check_n(char **av, int i);
int						check_dump(char **av, int i);
int						fill_players(char **av, t_vm *vm);

/*PROCESS*/
void					add_process(t_stack *stack, t_proc *proc);
void					delete_process(t_stack *stack, t_proc *proc);
t_proc					*init_process(t_vm *vm, int pc, int player);
void					increment_stack(t_vm *vm);
int						check_stack(t_vm *vm);
void					loop(t_vm *vm);
short					read_short(t_vm *vm, int pc);
int						read_int(t_vm *vm, int pc);
void					execute_process(t_vm *vm, t_proc *proc);
void					load_next_instruction(t_vm *vm, t_proc *proc);
void					read_params_content(t_operation *ope, int n, t_vm *vm, int *pc);
void					read_params_type(t_operation *ope, unsigned char ocp);
void					tab_to_type(char param_types[3], char arg[3]);

/*INSTRUCTION*/
void					live(t_vm *vm, t_proc *proc, t_operation *ope);
void					direct_load(t_vm *vm, t_proc *proc, t_operation *operation);
void					indirect_load(t_vm *vm, t_proc *proc, t_operation *operation);
void					long_indirect_load(t_vm *vm, t_proc *proc, t_operation *operation);
void					long_direct_load(t_vm *vm, t_proc *proc, t_operation *operation);
void					sub(t_vm *vm, t_proc *proc, t_operation *operation);
void					zjump(t_vm *vm, t_proc *proc, t_operation *ope);
void					add(t_vm *vm, t_proc *proc, t_operation *operation);
void					aff(t_vm *vm, t_proc *proc, t_operation *operation);
void					corewar_and(t_vm *vm, t_proc *proc, t_operation *operation);
void					corewar_or(t_vm *vm, t_proc *proc, t_operation *operation);
void					corewar_xor(t_vm *vm, t_proc *proc, t_operation *operation);
void					corewar_fork(t_vm *vm, t_proc *proc, t_operation *operation);
void					lfork(t_vm *vm, t_proc *proc, t_operation *operation);
void					direct_store(t_vm *vm, t_proc *proc, t_operation *operation);
void					indirect_store(t_vm *vm, t_proc *proc, t_operation *operation);

/*DISPLAY*/
void					display(t_vm *vm, int step);
void					create_visualizer(t_vm *vm, t_win *display);
void					display_winner(t_win *display);
void    				init_players(t_vm *vm);
void    				print_players_share(t_vm *vm);
void					ft_choose_color(int player);
void					display_pause(t_vm *vm);

/*DEBUG*/

void					print_process(t_proc *process);
void					print_vm(t_vm *vm);
void					print_stack(t_stack stack);
int						mod_pc(int value);
#endif
