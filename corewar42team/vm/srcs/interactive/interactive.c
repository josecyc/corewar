/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 06:54:27 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/11 10:02:30 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../includes/vm.h"

void		winner_print(t_player *p, t_arena *arena, t_window *win)
{
	t_player *tmp;

	if (arena->flags->interactive != 1)
	{
		return ;
	}
	tmp = p;
	wattron(win->down, COLOR_PAIR(3));
	while (tmp)
	{
		if (tmp->pnum == arena->last_alive)
		{
			mvwprintw(win->down, 3, 170, "WINNER IS \"%s\"", tmp->name);
			wattroff(win->down, COLOR_PAIR(3));
			wrefresh(win->down);
			getch_theses(win, arena, 1);
			return ;
		}
		tmp = tmp->next;
	}
	mvwprintw(win->down, 3, 170, "END OF THE GAME");
	wrefresh(win->down);
	wattroff(win->down, COLOR_PAIR(3));
	getch_theses(win, arena, 1);
}

void		landerer(t_data *data, t_player *tmp, t_window *win, t_arena *a)
{
	if (data->addr == tmp->pc_inter)
	{
		win->tab[data->addr] = abs(tmp->pnum);
		tmp->oldpc = tmp->pc_inter;
		data->power = tmp->prog_size;
		wattron(win->big, COLOR_PAIR(abs(tmp->pnum)));
		data->color = 1;
		print_color(win, a, *data);
	}
	else if (data->power)
	{
		win->tab[data->addr] = abs(tmp->pnum);
		data->color = 3;
		print_color(win, a, *data);
		data->power--;
		if (!data->power)
			wattroff(win->big, COLOR_PAIR(abs(tmp->pnum)));
	}
	else if (win->first_loop)
	{
		data->color = 3;
		print_color(win, a, *data);
	}
}

int			init_print(t_window *win, t_player *tmp, t_arena *arena)
{
	t_data data;

	ft_bzero(&data, sizeof(data));
	getbegyx(win->big, data.y, data.x);
	data.tmp = data.x + 2;
	data.x += 2;
	while (data.addr < MEM_SIZE)
	{
		if (data.x == data.tmp + 64 * 3)
		{
			data.x = data.tmp;
			data.y += 1;
		}
		landerer(&data, tmp, win, arena);
		data.addr += 1;
		data.x += 3;
		data.color = 0;
	}
	return (0);
}

void		loop_first_round(t_window *win, t_arena *arena, t_player *p)
{
	t_player	*tmp;
	t_data		data;

	ft_bzero(&data, sizeof(data));
	tmp = p;
	while (tmp)
	{
		init_print(win, tmp, arena);
		win->first_loop = 0;
		tmp = tmp->next;
	}
	win->first_round = 0;
	side_informations(win, p);
	wrefresh(win->big);
	wrefresh(win->side);
	wrefresh(win->down);
	getch_theses(win, arena, 1);
}

t_window	*interactive(t_player *players, t_arena *arena, t_window *win)
{
	getch_theses(win, arena, 0);
	down_infos(win, arena, players);
	write_mem(win, arena, players);
	side_informations(win, players);
	wrefresh(win->big);
	wrefresh(win->down);
	mvwprintw(win->down, 7, 5, "NUMBER OF PROCESS:\t     ");
	mvwprintw(win->down, 7, 75, "CYCLE COUNTER:\t     ");
	mvwprintw(win->down, 7, 5, "NUMBER OF PROCESS:\t   ");
	mvwprintw(win->down, 8, 75, "CYCLE TO DIE:\t     ");
	mvwprintw(win->down, 9, 75, "LIVE COUNTER:\t     ");
	wrefresh(win->side);
	usleep(win->sleep);
	return (win);
}
