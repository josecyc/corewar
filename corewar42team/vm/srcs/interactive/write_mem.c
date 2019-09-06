/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:36:54 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/05 18:29:45 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	print_color(WINDOW *big_win, t_player *p, t_arena *arena, t_data data, int i)
{
	
	if (data.color == 1)
	{
		wattron(big_win, A_BOLD);
		//wattron(big_win, COLOR_PAIR(abs(p->pnum)));
		mvwprintw(big_win, data.y, data.x, " %.2x", arena->memory[data.addr] & 255);
		wattroff(big_win, A_BOLD);
		/*
		wattron(big_win, A_BOLD);
		mvwprintw(big_win, data.y, data.x, " %.2x", arena->memory[data.addr] & 255);
		wattroff(big_win, A_BOLD);
		*/
	}
	else if (data.color == 2)
	{
		wattron(big_win, A_STANDOUT);
		mvwprintw(big_win, data.y, data.x, " %.2x", arena->memory[data.addr] & 255);
		wattroff(big_win, A_STANDOUT);
	}	
	
	else if (data.color == 3 && g_var == 0)
	{
		if (i == 0 || (i >= 1 && data.power))
			mvwprintw(big_win, data.y, data.x, " %.2x", arena->memory[data.addr] & 255);
	}
}

void	tag_pc(t_player *tmp, t_data *data, WINDOW *win)
{
	if (tmp->pc_inter == data->addr)
	{
		data->color = 1; // couleur de marquage
		tmp->coord[1] = data->y;
		tmp->coord[2] = data->x;
		if (g_var == 0)
		{
			data->power = tmp->prog_size + 1;
			wattron(win, COLOR_PAIR(abs(tmp->pnum)));
		}
	}
	else if (g_var == 0)
		data->color = 3;
	if (data->power)
	{
		data->power--;	
		if (!data->power)
			wattroff(win, COLOR_PAIR(abs(tmp->pnum)));
	}
}

void	color_old_pc(t_player *p, WINDOW *win, t_arena *arena)
{
	wattron(win, COLOR_PAIR(abs(p->pnum)));
	mvwprintw(win, p->coord[1], p->coord[2], " %.2x", arena->memory[p->oldpc] & 255);
	wattroff(win, A_BOLD);

}	

void	write_mem(WINDOW *big_win, t_arena *arena, t_player *p)
{
	t_data		data;
	t_player	*tmp;
	int			i;

	i = 0;
	tmp = p;
	while (tmp)
	{
		if (g_var != 0)
			color_old_pc(tmp, big_win, arena);
		ft_bzero(&data, sizeof(data));
		getbegyx(big_win, data.y, data.x);
		data.tmp = data.x + 2;
		data.x += 2;
		while (data.addr < MEM_SIZE)
		{
			while (data.x < data.tmp + 64 * 3)
			{
				tag_pc(tmp, &data, big_win);
				print_color(big_win, tmp, arena, data, i);
				data.x += 3;
				data.addr += 1;
				data.color = 0;
			}
			data.x = data.tmp;
			data.y += 1;
		}
		tmp->oldpc = tmp->pc - tmp->inst->size;
		tmp = tmp->next;
		i++;
	}
}
