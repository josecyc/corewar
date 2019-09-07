/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch_theses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:13:51 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/06 10:43:38 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	down_infos(t_window *win, t_arena *a)
{
	if (!a)
		return ;
	mvwprintw(win->down, 3, 5,"PRESS Q TO EXIT");
	mvwprintw(win->down, 4, 5,"PRESS SPACE TO TOGGLE PAUSE:\t%s", "OFF");
	mvwprintw(win->down, 6, 5,"SPEED:\t\tx%d  ", win->sleep_cursor);
	mvwprintw(win->down, 7, 5,"LIST OF PROCESS:\t\t%d", 6);
	mvwprintw(win->down, 8, 5,"CYCLES PER FRAME:\t\t%d", 6);
	/*
	 **	Random comment to make my brain clear
	 */
	mvwprintw(win->down, 6, 75,"TOTAL CYCLES:\t%d", a->total_cycles);
	mvwprintw(win->down, 7, 75,"CYCLE COUNTER:\t%d", a->cycle_counter);
	mvwprintw(win->down, 8, 75,"CYCLE TO DIE:\t%d", a->cycle_to_die);
}

void	close_win(void)
{
	curs_set(1);
	getch();
	endwin();
}

void	ft_sleep(int c, t_window *win)
{
	if (c == 'w' && win->sleep_cursor > 1)
	{
		win->sleep_cursor -= 1;
		win->sleep += MAX_UNIT_SLEEP;
	} 
	else if (c == 'e' && win->sleep_cursor < 10)
	{
		win->sleep_cursor = win->sleep_cursor + 1;
		win->sleep -= MAX_UNIT_SLEEP;
	}
}


void		getch_theses(t_window *win)
{
	int c;

	c = getch();
	if (c == ' ')
	{
		mvwprintw(win->down, 4, 5,"PRESS SPACE TO TOGGLE PAUSE:\t%s", "ON ");
		wrefresh(win->down);
		c = 0;
		while (c != ' ')
		{
			c = getch();
			if (c == 'q')
			{
				close_win();
				exit(1);
			}
		}
	}
	else if (c == 'q')
	{
		close_win();
		exit(1);
	}
	ft_sleep(c, win);
}

/*
 *	CYCLES PER FRAME == Amount of cycles that passed between each Visualizer 
 *	refresh
 */
