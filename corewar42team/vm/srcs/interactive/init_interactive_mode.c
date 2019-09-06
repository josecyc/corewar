/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interactive_mode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 07:12:56 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/05 16:20:33 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void error_handler_inter(int error)
{
	int token;

	endwin();
	if (error == 1)
		ft_putendl("\033[1;32mThis terminal window is too small, please expend it for decent visibility\033[0m");
	if (error == 2)
		ft_putendl("\033[1;32mThis terminal dont support colors\033[0m");
	if (error == 3)
		ft_putendl("\033[1;32mToo much players, modify var MAX_PLAYERS\033[0m");
	exit(error);
}

WINDOW *create_newwin(int height, int width, int starty, int startx, char *title)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	mvwprintw(local_win, 0,  width / 2 - ft_strlen(title), title);

	return local_win;
}

void			set_up_colors()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

t_window		*init_interactive_mode(void)
{
	t_window	*win;
	int x;

	initscr();
	start_color();
	set_up_colors();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	if (COLS < 60 || LINES < 60)
		error_handler_inter(WINDOW_TOO_SMALL);
	else if (has_colors() == FALSE)
		error_handler_inter(NO_COLORS);
	else if (MAX_PLAYERS > 7)
		error_handler_inter(TOO_MUCH_PPL);
	if (!(win = malloc(sizeof(t_window*))))
	{
		close_win();
		exit(1);
	}
	win->big = create_newwin(LINES * 0.84, COLS * 0.85, LINES - LINES + 1,
			COLS - COLS + 1, "ARENA");
	win->side = create_newwin(LINES * 0.84, COLS * 0.15, LINES - LINES + 1,
			(COLS * 0.85) + 1, "DATA");
	win->down = create_newwin(LINES * 0.16, COLS - 1, LINES - (LINES * 0.16 - 1),
			(COLS - COLS + 1), "EXTRA_DATA");
	return (win);
}
