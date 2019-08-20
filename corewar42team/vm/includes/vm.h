/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:56:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/02/04 10:00:55 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
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
}					        t_flag;

typedef struct		s_inst
{
	int 			counter;
	int				op_code;
	unsigned char	ebyte;
	int				args[3];
}					t_inst;

typedef struct		s_player
{
	int				reg[16];
	int				carry;
	int				life_bl;
	int				dead;
	//int				xy[2];   //start location
	int				pc;
	int				pnum;	
	t_inst			*inst;
	int				total_size;
	int				prog_size;
	int				actual_size;
	char			*name;
	char			*comment;
	char			*prog;
	struct s_player *next;
	int				first;
}					t_player;

typedef struct	s_arena
{
	int			argc;
	char		**argv;
	char		memory[MEM_SIZE];
	int			num_plys;
	int			cycle_to_die;
	int			total_cycles;
	int			cycle_counter;
	int			checkup_counter;
	int			live_counter;
	t_flag		*flags;
	int			last_alive;
}				t_arena;

typedef struct			s_windows
{
	WINDOW				*win;
	struct s_windows	*next;
}						t_windows;

typedef			int t_inst_funct(t_player *player, t_arena *arena);

/*
* Initial State (part 1)
*/

/*
** arena.c
*/
int				init_arena(t_arena *arena, t_player **player);

/*
** errorh.c
*/
int				print_error(int errnum, t_player *fplayer, t_arena *arena);

/*
** flags.c
*/
//int				get_flags(t_arena *arena, int *i, t_player *fplayer);
int				get_flags(t_arena *arena, int *i);

/*
** init_objs.c
*/
void			init_arena_ob(t_arena *arena, int argc, char **argv);

/*
** players.c
*/
int				get_player(t_arena *arena, t_player **player, int *i);

/*
** players_utils.c
*/
t_player		*add_player(t_player **head);
t_player		*create_player();

/*
** print_memory.c
*/
void			print_memory(char memory[MEM_SIZE]);
void			print_info(t_arena *arena, t_player *fplayer);

/*
** Main Loop (Part 2)
*/

/*
** graphics.c
*/
void			graphics(t_arena *arena, t_player *fplayer);

/*
** live_checkup.c
*/
int				live_checkup(t_player *players, t_arena *arena);

/*
** loop.c
*/
void			loop(t_player *players, t_arena *arena);

/*
**	save_inst
*/
int				save_inst(t_player *player, t_arena *arena);

/*
** windows.c
*/
void			init_windows(t_windows **window_head);

#endif
