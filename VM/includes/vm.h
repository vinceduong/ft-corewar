/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:10:14 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/30 17:50:31 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>
# include <ncurses.h>

# define MAX_SPEED 1
# define MIN_SPEED 1000000
# define SPEED_STEP 3000
# define DISPLAY_FREQUENCY 100000
# define GLOW_CYCLE 49

typedef struct	s_player
{
	int				number;
	unsigned char	prog[CHAMP_MAX_SIZE];
	t_header		header;
	int				nb_live;
	int				last_live;
}				t_player;

typedef struct	s_instruction
{
	int				opcode;
	int				ocp;
	t_arg_type		param_types[3];
	int				params[3];
	int				invalid;
}				t_instruction;

typedef struct	s_proc
{
	int				r[REG_NUMBER];
	int				pc;
	char			carry;
	int				cycles;
	int				lives;
	int				alive;
	char			opcode;
	int				id;
	struct s_proc	*next;
}				t_proc;

typedef struct	s_vm
{
	unsigned char	ram_glow[MEM_SIZE];
	unsigned char	ram[MEM_SIZE];
	unsigned char	ram_color[MEM_SIZE];
	unsigned char	ram_viewed[MEM_SIZE];
	t_proc			*processes;
	int				num_processes;
	int				proc_created;
	int				num_players;
	t_player		players[MAX_PLAYERS];
	int				cycle_to_die;
	int				num_lives;
	int				tot_lives;
	int				check_cycles;
	int				checks;
	int				cycle;
	int				dump_cycle;
	int				show_lives;
	int				win;
	int				visu;
	int				speed;
	int				pause;
	struct timeval	last_display;
	int				sbs;
	t_proc			*viewed_process;
	int				winner;
}				t_vm;

typedef struct	s_win
{
	WINDOW 		*win;
	WINDOW		*win_left;
	WINDOW		*win_right;
	WINDOW		*win_down;
	int			lines;
	int			cols;
}				t_win;

int				ft_printf(const char *format, ...);
void			(*g_op_functions[16])(t_vm*, t_proc*, t_instruction*);

void			init_vm(t_vm *vm);
void			handle_main_loop(t_vm *vm);

void			create_process(t_vm *vm, int pc, int player_num, int no_init);
void			kill_process(t_proc *process, t_vm *vm);

void			execute_instruction(t_proc *process, t_vm *vm);
void			pre_execute_instruction(t_proc *process, t_vm *vm);

void			ocp_to_param_types(t_instruction *inst, unsigned char ocp);

int				check_processes(t_vm *vm);

void			parse(int argc, char **argv, t_vm *vm);
void			load_player(t_player *p, const char *name, t_vm *vm);
int				invalid_int(char *s);

void			dump_ram(t_vm *vm);

int				swap_int(int n);
unsigned int	swap_uint(unsigned int n);
short			swap_short(short n);

short			two_octets_to_short(unsigned char ram[MEM_SIZE], int pc);
int				four_octets_to_int(unsigned char ram[MEM_SIZE], int pc);

void			init_ncurses(t_vm *vm);
int				sleep_display(t_vm *vm);
void			display_ram(t_vm *vm);
void			change_ram_color(t_vm *vm, int pc, int pc_dest, int p_id);
void			display_players(t_vm *vm, WINDOW *info, int *line);
void			clear_viewed(t_vm *vm, WINDOW *info, int line);

//void			display_winner(t_vm *vm);
void			display_winner_ncurse(t_vm *vm, WINDOW *info, int line);

/*
** Instructions
*/

void			add(t_vm *vm, t_proc *proc, t_instruction *inst);
void			sub(t_vm *vm, t_proc *proc, t_instruction *inst);

void			cor_and(t_vm *vm, t_proc *proc, t_instruction *inst);
void			cor_or(t_vm *vm, t_proc *proc, t_instruction *inst);
void			cor_xor(t_vm *vm, t_proc *proc, t_instruction *inst);

void			direct_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			direct_store(t_vm *vm, t_proc *proc, t_instruction *inst);
void			indirect_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			indirect_store(t_vm *vm, t_proc *proc, t_instruction *inst);
void			long_indirect_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			long_direct_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			long_direct_store(t_vm *vm, t_proc *proc, t_instruction *inst);

void			live(t_vm *vm, t_proc *proc, t_instruction *inst);
void			zjmp(t_vm *vm, t_proc *proc, t_instruction *inst);
int				mod_adr(int adr);

void			cor_fork(t_vm *vm, t_proc *src, t_instruction *inst);
void			cor_lfork(t_vm *vm, t_proc *src, t_instruction *inst);

void			aff(t_vm *vm, t_proc *proc, t_instruction *inst);

#endif
