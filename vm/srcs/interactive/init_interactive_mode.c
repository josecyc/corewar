/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interactive_mode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 07:12:56 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/14 12:04:43 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			error_handler_inter(int error)
{
	endwin();
	if (error == 1)
	{
		ft_putstr("\033[1;32mThis terminal window is too small, ");
		ft_putendl("please expend it for decent visibility\033[0m");
	}
	if (error == 2)
		ft_putendl("\033[1;32mThis terminal dont support colors\033[0m");
	if (error == 3)
		ft_putendl("\033[1;32mToo much players, modify var MAX_PLAYERS\033[0m");
	close_win();
	exit(error);
}

WINDOW			*create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	return (local_win);
}

void			set_up_colors(void)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
}

void			init_win_data(t_window *win)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
		win->tab[i++] = 0;
	win->sleepc = 5;
	win->first_round = 1;
	win->first_loop = 1;
	win->sleep = MIN_UNIT_SLEEP - (5 * MAX_UNIT_SLEEP);
	win->big = create_newwin(LINES * 0.84, COLS * 0.80, LINES - LINES + 1,
			COLS - COLS + 1);
	mvwprintw(win->big, 0, (COLS * 0.8) / 2 - 11, "%s", " - ARENA - ");
	win->side = create_newwin(LINES * 0.84, COLS * 0.20, LINES - LINES + 1,
			(COLS * 0.80) + 1);
	mvwprintw(win->side, 0, (LINES * 0.84) / 2 - 10, "%s", " - DATA - ");
	win->down = create_newwin(LINES * 0.16,
			COLS - 1, LINES - (LINES * 0.16 - 1),
			(COLS - COLS + 1));
	mvwprintw(win->down, 0, (COLS - 1) / 2 - 13, "%s", " - COMMANDS - ");
}

t_window		*init_interactive_mode(t_window *win)
{
	initscr();
	start_color();
	set_up_colors();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	if (COLS < 246 || LINES < 74)
		error_handler_inter(WINDOW_TOO_SMALL);
	else if (has_colors() == FALSE)
		error_handler_inter(NO_COLORS);
	else if (MAX_PLAYERS > 7)
		error_handler_inter(TOO_MUCH_PPL);
	init_win_data(win);
	return (win);
}
