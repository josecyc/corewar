/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 06:54:27 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/05 18:23:46 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../includes/vm.h"
//WINDOW *create_newwin(int height, int width, int starty, int startx, char *title);
void destroy_win(WINDOW *local_win);

void		interactive(t_player *players, t_arena *arena, t_window *win)
{
	int x;
	int y;

	getmaxyx(stdscr, y, x);	
	getch_theses(win->down);
	down_infos(win->down, arena);
	write_mem(win->big, arena, players);
	wrefresh(win->big);
	wrefresh(win->down);
	wrefresh(win->side);
	g_var = 1;
	usleep(100000);
}

void destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
