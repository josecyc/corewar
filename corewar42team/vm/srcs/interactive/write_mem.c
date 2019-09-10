/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:36:54 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/09 21:33:12 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	print_color(t_window *win, t_arena *arena, t_data data)
{
	if (data.color == 2)
	{
		wattron(win->big, A_BOLD);
		mvwprintw(win->big, data.y, data.x, " %.2x",
				arena->memory[data.addr] & 255);
		wattroff(win->big, A_BOLD);
	}
	else if (data.color == 1)
	{
		mvwprintw(win->big, data.y, data.x++, " ",
				arena->memory[data.addr] & 255);
		wattron(win->big, A_STANDOUT);
		mvwprintw(win->big, data.y, data.x, "%.2x",
				arena->memory[data.addr] & 255);
		wattroff(win->big, A_STANDOUT);
	}
	else if (data.color == 3)
	{
		mvwprintw(win->big, data.y, data.x, " %.2x",
				arena->memory[data.addr] & 255);
	}
}

void	ft_update_coord(t_data *data, int value, WINDOW *win)
{
	ft_bzero(data, sizeof(data));
	getbegyx(win, data->y, data->x);
	data->tmp = data->x + 2;
	data->x += 2;
	if (data->addr == value)
		return ;
	while (data->addr <= MEM_SIZE)
	{
		data->x += 3;
		data->addr += 1;
		if (data->x == data->tmp + 64 * 3)
		{
			data->x = data->tmp;
			data->y += 1;
		}
		if (data->addr == value)
			break ;
	}
}

void	do_movement(t_data *data, t_player *tmp)
{
	if (MAX_Y == data->y && MAX_X == data->x)
	{
		data->y = 1;
		data->x = 3;
		tmp->write_addr = 0;
		return ;
	}
	if (data->x == MAX_X)
	{
		data->x = 3;
		data->y += 1;
		return ;
	}
	data->x += 3;
	tmp->write_addr++;
}

void	change_arena(t_data data, t_player *tmp, t_arena *arena, t_window *win)
{
	while (tmp)
	{
		if (tmp->write_bl)
		{
			tmp->write_bl = 0;
			data.addr = 0;
			ft_update_coord(&data, tmp->write_addr, win->big);
			data.power = 4;
			wattron(win->big, COLOR_PAIR(abs(tmp->pnum)));
			while (data.power)
			{
				win->tab[tmp->write_addr] = abs(tmp->pnum);
				mvwprintw(win->big, data.y, data.x, " %.2x",
						arena->memory[tmp->write_addr] & 255);
				data.power--;
				do_movement(&data, tmp);
				wrefresh(win->side);
			}
			wattroff(win->big, COLOR_PAIR(abs(tmp->pnum)));
		}
		tmp = tmp->next;
	}
}

void	write_mem(t_window *win, t_arena *arena, t_player *p)
{
	t_player	*tmp;
	t_data		data;

	ft_bzero(&data, sizeof(data));
	tmp = p;
	if (win->first_round)
		loop_first_round(win, arena, p);
	change_pc(data, tmp, arena, win);
	change_arena(data, tmp, arena, win);
}
