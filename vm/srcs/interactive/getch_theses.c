/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch_theses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:13:51 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/09 21:41:28 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		close_win(void)
{
	curs_set(1);
	getch();
	endwin();
}

void		ft_sleep(int c, t_window *win)
{
	wattron(win->down, COLOR_PAIR(2));
	if (c == 'w' && win->sleepc > 1)
	{
		win->sleepc -= 1;
		win->sleep += MAX_UNIT_SLEEP;
		mvwprintw(win->down, 6, 5, "SPEED:\tx%d  ", win->sleepc);
	}
	else if (c == 'e' && win->sleepc < 10)
	{
		win->sleepc = win->sleepc + 1;
		win->sleep -= MAX_UNIT_SLEEP;
		mvwprintw(win->down, 6, 5, "SPEED:\tx%d  ", win->sleepc);
	}
	else if (c == 'q')
	{
		close_win();
		exit(1);
	}
	wattroff(win->down, COLOR_PAIR(2));
}

void		getch_theses(t_window *win, t_arena *arena, int index)
{
	int c;

	c = getch();
	if (c == ' ' || index == 1)
	{
		bottom_informations(win, arena, 2);
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
			if (c == 'e' || c == 'w')
			{
				ft_sleep(c, win);
				wrefresh(win->down);
			}
		}
	}
	ft_sleep(c, win);
}
