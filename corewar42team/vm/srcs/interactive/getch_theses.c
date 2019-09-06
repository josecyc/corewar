/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch_theses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:13:51 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/05 18:23:44 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	down_infos(WINDOW *win, t_arena *a)
{
	if (!a)
		return ;
	mvwprintw(win, 3, 5,"PRESS Q TO EXIT");
	mvwprintw(win, 4, 5,"PRESS SPACE TO TOGGLE PAUSE:\t%s", "OFF");
	mvwprintw(win, 6, 5,"FRAMES PER SECOND:\t\t%d", 6);
	mvwprintw(win, 7, 5,"LIST OF PROCESS:\t\t%d", 6);
	mvwprintw(win, 8, 5,"CYCLES PER FRAME:\t\t%d", 6);
	/*
	**	Random comment to make my brain clear
	*/
	mvwprintw(win, 6, 75,"TOTAL CYCLES:\t\t%d", a->total_cycles);
	mvwprintw(win, 7, 75,"CYCLE COUNTER:\t\t%d", a->cycle_counter);
	mvwprintw(win, 8, 75,"CYCLE TO DIE:\t%d", a->cycle_to_die);
}

void	close_win(void)
{
	curs_set(1);
	getch();
	endwin();
}

void	getch_theses(WINDOW *win)
{
	int c;

	c = getch();
	if (c == ' ')
	{
		mvwprintw(win, 4, 5,"PRESS SPACE TO TOGGLE PAUSE:\t%s", "ON ");
		wrefresh(win);
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
}

/*
 *	CYCLES PER FRAME == Amount of cycles that passed between each Visualizer 
 *	refresh
 */
