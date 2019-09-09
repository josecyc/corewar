/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch_theses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:13:51 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/09 16:11:05 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			nb_process(t_player *p)
{
	int			ret;
	t_player	*tmp;

	tmp = p;
	ret = 0;
	while (tmp)
	{
		if (!p->dead)
			ret++;
		tmp = tmp->next;
	}
	return (ret);
}

void		down_infos(t_window *win, t_arena *a, t_player *p)
{
	if (!a)
		return ;
	mvwprintw(win->down, 3, 5, "PRESS Q TO EXIT");
	mvwprintw(win->down, 4, 5, "PRESS SPACE TO USE PAUSE:\t%s", "RUNNING");
	mvwprintw(win->down, 6, 5, "SPEED:\t\tx%d  ", win->sleepc);
	mvwprintw(win->down, 7, 5, "NUMBER OF PROCESS:\t\t%d", nb_process(p));
	mvwprintw(win->down, 6, 75, "TOTAL CYCLES:\t%d", a->total_cycles);
	mvwprintw(win->down, 7, 75, "CYCLE COUNTER:\t%d", a->cycle_counter);
	mvwprintw(win->down, 8, 75, "CYCLE TO DIE:\t%d", a->cycle_to_die);
}

void		close_win(void)
{
	curs_set(1);
	getch();
	endwin();
}

void		ft_sleep(int c, t_window *win)
{
	if (c == 'w' && win->sleepc > 1)
	{
		win->sleepc -= 1;
		win->sleep += MAX_UNIT_SLEEP;
	}
	else if (c == 'e' && win->sleepc < 10)
	{
		win->sleepc = win->sleepc + 1;
		win->sleep -= MAX_UNIT_SLEEP;
	}
	else if (c == 'q')
	{
		close_win();
		exit(1);
	}
}

void		getch_theses(t_window *win, int index)
{
	int c;

	c = getch();
	if (c == ' ' || index == 1)
	{
		mvwprintw(win->down, 4, 5, "PRESS SPACE TO USE PAUSE:\t%s", "PAUSED ");
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
				mvwprintw(win->down, 6, 5, "SPEED:\t\tx%d  ", win->sleepc);
				wrefresh(win->down);
			}
		}
	}
	ft_sleep(c, win);
}
