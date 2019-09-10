/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_informations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:34:13 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/09 21:38:17 by viclucas         ###   ########.fr       */
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

void		bottom_informations(t_window *win, t_arena *a, int value)
{
	if (value == 2)
	{
		mvwprintw(win->down, 4, 5, "PRESS SPACE TO USE PAUSE:\t");
		wattron(win->down, COLOR_PAIR(3));
		mvwprintw(win->down, 4, 33, "PAUSED  ");
		wattroff(win->down, COLOR_PAIR(3));
		return ;
	}
	wattron(win->down, COLOR_PAIR(3));
	mvwprintw(win->down, 4, 33, "RUNNING");
	wattroff(win->down, COLOR_PAIR(3));
	if (a->cycle_to_die <= 0)
	{
		wattron(win->down, COLOR_PAIR(3));
		mvwprintw(win->down, 8, 75, "CYCLE TO DIE:\t%s", "FINISHED");
		wattroff(win->down, COLOR_PAIR(3));
	}
	else
		mvwprintw(win->down, 8, 75, "CYCLE TO DIE:\t%d", a->cycle_to_die);
}

void		down_infos(t_window *win, t_arena *a, t_player *p)
{
	if (!a || !p || !win)
		return ;
	mvwprintw(win->down, 3, 5, "PRESS Q TO EXIT");
	mvwprintw(win->down, 4, 5, "PRESS SPACE TO USE PAUSE:\t");
	bottom_informations(win, a, 1);
	wattron(win->down, COLOR_PAIR(2));
	mvwprintw(win->down, 6, 5, "SPEED:\tx%d  ", win->sleepc);
	mvwprintw(win->down, 6, 25, "<< w | p >>");
	wattroff(win->down, COLOR_PAIR(2));
	mvwprintw(win->down, 7, 5, "NUMBER OF PROCESS:\t\t%d", nb_process(p));
	mvwprintw(win->down, 6, 75, "TOTAL CYCLES:\t%d", a->total_cycles);
	mvwprintw(win->down, 7, 75, "CYCLE COUNTER:\t%d", a->cycle_counter);
}
