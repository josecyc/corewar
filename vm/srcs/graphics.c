/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:49:47 by tholzheu          #+#    #+#             */
/*   Updated: 2019/02/04 09:06:07 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		print_arena(char memory[MEM_SIZE], t_player *fplayer, t_windows *window_head)
{
	int			x;
	int			y;
	int			addr;
	int			tmp;
	int			pl_count;
	int			color_pair_nb;

	getbegyx(window_head->win, y, x);
	y += 10;
	x += 25;
	addr = 0;
	pl_count = 0;
	tmp = x;
	color_pair_nb = 1;
	(void)fplayer;
	while (addr < MEM_SIZE)
	{
		while (x < tmp + 64 * 3)
		{
			/*if (fplayer && fplayer->pc + pl_count == addr && pl_count++ < )*/
				/*attron(COLOR_PAIR(color_pair_nb));*/
			mvprintw(y, x, " %.2x", memory[addr] & 255);
			attron(COLOR_PAIR(1));
			x += 3;
			addr++;
		}
		x = tmp;
		y++;
	}
}

static void		init_colors(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
}

void	 		graphics(t_arena *arena, t_player *fplayer)
{	
	t_windows	*window_head;
	/*int			y;*/
	/*int			x;*/

	initscr();			/* Start curses mode 		*/
	init_colors();
	window_head = NULL;
	init_windows(&window_head);
	print_arena(arena->memory, fplayer, window_head);
	curs_set(0);
	getch();
	endwin();			/* End curses mode		  */
}

/*int				main(void)*/
/*{*/
	/*graphics();*/
	/*return (0);*/
/*}*/
