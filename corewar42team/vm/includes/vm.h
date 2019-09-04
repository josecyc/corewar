/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:56:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/03 22:07:19 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# define WINDOW_TO_SMALL 1
# define NO_COLORS 2
# include "../../assembler/includes/op.h"
# include "../../assembler/includes/assembler.h"
# include <ncurses.h>
# include "../../libft/libft.h"
# define FLAGSC "id"
# define OPTIONS "OPTIONS ARE:\n-i for interactive mode\n-n [desired_player_num] [player]\n-dump [cycles] for dumping arena memory\n"

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
	int 			counter;
	int				op_code;
	unsigned char	ebyte;
	int				args[3];
	int				size;
}					t_inst;

typedef struct		s_player
{
	int				reg[REG_NUMBER];
	int				carry;
	int				life_bl;
	int				dead;
	//int			xy[2];   //start location
	int				pc;
	int				pnum;	
	t_inst			*inst;
	int				total_size;
	int				prog_size;
	int				actual_size; //?
	char			*name;
	char			*comment;
	char			*prog;
	struct s_player *next;
	int				first;  //?
}					t_player;

typedef struct		s_arena
{
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

typedef struct		s_win
{
	WINDOW			*win;
	struct s_win	*next;
}					t_wins;

typedef	void		(*t_inst_funct)(t_player *player, t_arena *arena);

/*
* Initial State (part 1)
*/

/*
** arena.c
*/
int					init_arena(t_arena *arena, t_player **player);

/*
** errorh.c
*/
int					print_error(int errnum, t_player *fplayer, t_arena *arena);

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

/*
** live_checkup.c
*/
int					live_checkup(t_player *players, t_arena *arena);

/*
** loop.c
*/
void				loop(t_player *players, t_arena *arena);

/*
**	save_inst
*/
int					save_inst(t_player *player, t_arena *arena);
int					memory_to_int(int *dest, t_arena *arena, int src_addr, int bytes);

/*
** windows.c
*/
void				init_windows(t_wins **window_head);

/*
 *
** graphic_bonus.c
*/
int					graph_bonus(t_player *players, t_arena *arena);

/*
** init_players.c
*/
int					init_player(int fd, t_arena *arena, t_player **fplayer);
int					verify_program(t_player **fplayer, char *prog, int size);
int					assign_number(t_player *fplayer, int cur_pl_num);

/*
** inst_utils.c
*/
int					advance_proc_pc(t_player **player, int step);
int					get_addr_value(t_player *player, int step);

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
void				inst_fork(t_player *fplayer, t_arena *arena);
t_player    		*add_process_last(t_player **any_process);
void				inst_lld(t_player *fplayer, t_arena *arena);
void				inst_lldi(t_player *fplayer, t_arena *arena);
void				inst_lfork(t_player *fplayer, t_arena *arena);
void				inst_aff(t_player *fplayer, t_arena *arena);


#endif
