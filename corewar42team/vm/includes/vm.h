/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:56:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/10 19:11:51 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <ncurses.h>
# define MAX_X 192
# define MAX_Y 64
# define MIN_UNIT_SLEEP 100000
# define MAX_UNIT_SLEEP 10000
# define INIT_SPEED 1
# define HEIGHT_DOWN 10
# define WINDOW_TOO_SMALL 1
# define NO_COLORS 2
# define TOO_MUCH_PPL 3
# include "../../assembler/includes/op.h"
# include "../../assembler/includes/assembler.h"
# include "../../libft/libft.h"
# define FLAGSC "id"

typedef struct		s_flag
{
	int				dump_bl;
	int				dump_cycles;
	int				n_bl;
	int				n_pnum;
	int				interactive;
}					t_flag;

typedef struct		s_inst
{
	int				counter;
	int				op_code;
	unsigned char	ebyte;
	int				args[3];
	int				size;
	int				fork;
}					t_inst;

typedef struct		s_player
{
	int				reg[REG_NUMBER];
	int				carry;
	int				life_bl;
	int				dead;
	int				write_bl;
	int				write_addr;
	int				pc;
	int				pnum;
	t_inst			*inst;
	int				total_size;
	int				prog_size;
	int				actual_size;
	char			*name;
	char			*comment;
	char			*prog;
	int				oldpc;
	int				proc_num;
	int				pc_inter;
	char			valid_arg_type;
	int				j;
	struct s_player *next;
}					t_player;

typedef struct		s_window
{
	WINDOW	*big;
	WINDOW	*side;
	WINDOW	*down;
	int		tab[MEM_SIZE];
	int		index;
	int		first_loop;
	int		first_round;
	int		sleepc;
	int		sleep;
}					t_window;

typedef struct		s_data
{
	int				power;
	int				x;
	int				y;
	int				addr;
	int				tmp;
	int				color;
	int				empty_turn;
	int				update_coord;
}					t_data;

typedef struct		s_arena
{
	t_player		*first;
	int				argc;
	char			**argv;
	char			memory[MEM_SIZE];
	int				num_plys;
	int				cycle_to_die;
	int				total_cycles;
	int				cycle_counter;
	int				checkup_counter;
	int				live_counter;
	t_flag			*flags;
	int				last_alive;
}					t_arena;

typedef	void		(*t_inst_funct)(t_player *player, t_arena *arena);

/*
** Initial State (part 1)
*/

/*
** arena.c
*/
int					init_arena(t_arena *arena, t_player **player);

/*
** errorh.c
*/
int					print_error(int errnum, t_player *fplayer, t_arena *arena);
int					print_error2(int errnum, t_player *fplayer, t_arena *arena);

/*
** flags.c
*/
int					get_flags(t_arena *arena, int *i, t_player **fplayer);

/*
** init_objs.c
*/
void				init_arena_ob(t_arena *arena, int argc, char **argv);

/*
** players.c
*/
int					get_player(t_arena *arena, t_player **player, int *i);

/*
** players_utils.c
*/
t_player			*add_player(t_player **head);
t_player			*create_player();

/*
** print_memory.c
*/
void				print_memory(char memory[MEM_SIZE]);
void				print_info(t_arena *arena, t_player *fplayer);

/*
** Main Loop (Part 2)
*/

/*
** graphics.c
*/
void				graphics(t_arena *arena, t_player *fplayer);
void				winner_print(t_player *p, t_arena *arena, t_window *win);

/*
** live_checkup.c
*/
int					live_checkup(t_player *players, t_arena *arena);

/*
** loop.c
*/
void				loop(t_player *players, t_arena *arena);
void				announce_winner(t_player *players, t_arena *arena);

/*
**	save_inst
*/
int					put_cycle(t_player *player, t_arena *arena);
int					save_inst(t_player *player, t_arena *arena);
int					memory_to_int(int *dest, t_arena *arena, int src_addr,
					int bytes);

/*
** Interactive folder:
** bottom_informations.c
*/
void				bottom_informations(t_window *win, t_arena *a, int value);
void				down_infos(t_window *win, t_arena *a, t_player *p);

/*
**	getch_theses.c
*/
void				getch_theses(t_window *win, t_arena *arena, int index);
void				close_win(void);

/*
**	init_interactive_mode.c
*/
t_window			*init_interactive_mode(t_window *win);

/*
**	interactive.c
*/
t_window			*interactive(t_player *players, t_arena *arena,
					t_window *win);
void				loop_first_round(t_window *win, t_arena *arena,
					t_player *p);

/*
**	pc_management.c
*/
void				change_pc(t_data data, t_player *tmp, t_arena *arena,
					t_window *win);

/*
**	side_informations.c
*/
void				side_informations(t_window *win, t_player *players);

/*
**	write_mem.c
*/
void				write_mem(t_window *win, t_arena *arena, t_player *player);
void				ft_update_coord(t_data *data, int value, WINDOW *win);
void				print_color(t_window *win, t_arena *arena, t_data data);

/*
** End of Interactive folder, back to poor quality code just below
*/

/*
** init_players.c
*/
int					init_player(int fd, t_arena *arena, t_player **fplayer);
int					verify_program(t_player **fplayer, char *prog, int size);
int					assign_number(t_player *fplayer, int cur_pl_num);
void				color_pc(t_window *win, t_arena *arena, t_player *tmp);

/*
** inst_utils.c
*/
int					ebyte_to_args(t_player *player, t_arena *arena, int *step);
int					save_without_eb(t_player *player, t_arena *arena,
					int *step);
int					valid_reg(t_arena *arena, t_player *player, int step);
int					valid_reg_int(t_player *player, int num);
int					valid_ebyte(char e_pair, char valid_arg_types);
int					advance_proc_pc(t_player **player, int step);
int					get_addr_value(t_player *player, int step);
int					jump_next_op(int nbr);
int					put_cycle(t_player *player, t_arena *arena);

/*
** instructions
*/

void				inst_live(t_player *fplayer, t_arena *arena);
void				inst_ld(t_player *fplayer, t_arena *arena);
void				inst_st(t_player *fplayer, t_arena *arena);
void				inst_add(t_player *fplayer, t_arena *arena);
void				inst_sub(t_player *fplayer, t_arena *arena);
void				inst_and(t_player *fplayer, t_arena *arena);
void				inst_or(t_player *fplayer, t_arena *arena);
void				inst_xor(t_player *fplayer, t_arena *arena);
void				inst_zjmp(t_player *fplayer, t_arena *arena);
void				inst_ldi(t_player *fplayer, t_arena *arena);
void				inst_sti(t_player *fplayer, t_arena *arena);
void				inst_fork(t_player **head, t_arena *arena, t_player *cur);
void				inst_lld(t_player *fplayer, t_arena *arena);
void				inst_lldi(t_player *fplayer, t_arena *arena);
void				inst_lfork(t_player **head, t_arena *arena, t_player *cur);
void				inst_dummy(t_player *fplayer, t_arena *arena);
void				inst_dummy2(t_player *fplayer, t_arena *arena);
void				inst_aff(t_player *fplayer, t_arena *arena);

#endif
