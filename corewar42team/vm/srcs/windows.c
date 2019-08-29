/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:43:50 by tholzheu          #+#    #+#             */
/*   Updated: 2019/02/02 19:11:43 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static t_windows	*new_t_window(WINDOW *win)
{
	t_windows	*new;

	new = (t_windows *)malloc(sizeof(t_windows));
	if (!new)
		return (NULL);
	new->win = win;
	new->next = NULL;
	return (new);
}

static void			add_window_back(t_windows **window_head, WINDOW *win)
{
	t_windows	*cur;
	t_windows	*new;

	new = new_t_window(win);
	if (*window_head == NULL)
	{
		*window_head = new;
		return ;
	}
	cur = *window_head;
	while (cur && cur->next)
		cur = cur->next;
	cur->next = new;
}

static WINDOW 		*create_mainwin(int height, int width, int starty, int startx)
{	
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	wborder(local_win, '>', '<', 'V', 'V', '>', '<', '>', '<');
	refresh();
	wrefresh(local_win);
	return (local_win);
}

static WINDOW 		*create_sidewin(int height, int width, int starty, int startx)
{	
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	wrefresh(local_win);
	refresh();
	return (local_win);
}

void				init_windows(t_windows **window_head)
{
	WINDOW *my_win;

	my_win = create_mainwin(LINES, LINES * 3, 0, (COLS - LINES * 3) / 2);
	add_window_back(window_head, my_win);
	my_win = create_sidewin(LINES / 2.5, LINES / 2.5 * 1.7, 0, 0); // top left
	add_window_back(window_head, my_win);
	my_win = create_sidewin(LINES / 2.5, LINES / 2.5 * 1.7, 0, 308); // top right
	add_window_back(window_head, my_win);
	my_win = create_sidewin(LINES / 2.5, LINES / 2.5 * 1.7, LINES / 2.5, 0); // middle left
	add_window_back(window_head, my_win);
	my_win = create_sidewin(LINES / 2.5, LINES / 2.5 * 1.7, LINES / 2.5, 308); // middle right
	add_window_back(window_head, my_win);
	my_win = create_sidewin(LINES / 5, LINES / 5 * 3.5, LINES / 2.5 * 2, 0); // bottom left
	add_window_back(window_head, my_win);
	my_win = create_sidewin(LINES / 5, LINES / 5 * 3.5, LINES / 2.5 * 2, 308); // bottom right
	add_window_back(window_head, my_win);
}
