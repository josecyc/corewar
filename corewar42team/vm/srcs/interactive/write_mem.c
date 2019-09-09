/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:36:54 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/09 10:45:40 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	print_color(t_window *win, t_player *p, t_arena *arena, t_data data)
{
	(void)p;
	if (data.color == 2)
	{
		wattron(win->big, A_BOLD);
		mvwprintw(win->big, data.y, data.x, " %.2x", arena->memory[data.addr] & 255);
		wattroff(win->big, A_BOLD);
	}
	else if (data.color == 1)
	{
		mvwprintw(win->big, data.y, data.x++, " ", arena->memory[data.addr] & 255);
		wattron(win->big, A_STANDOUT);
		mvwprintw(win->big, data.y, data.x, "%.2x", arena->memory[data.addr] & 255);
		wattroff(win->big, A_STANDOUT);
	}	
	else if (data.color == 3)
	{
		mvwprintw(win->big, data.y, data.x, " %.2x", arena->memory[data.addr] & 255);
	}
}
/*
void	tag_pc(t_player *tmp, t_data *data, t_window *win)
{
	if (tmp->pc_inter == data->addr)
	{
		data->color = 1; // couleur de marquage
		tmp->coord[1] = data->y;
		tmp->coord[2] = data->x;
		if (g_var == 0)
		{
			data->power = tmp->prog_size + 1;
			wattron(win->big, COLOR_PAIR(abs(tmp->pnum)));
		}
	}
	else if (tmp->write_addr == data->addr && tmp->write_bl)
	{
		data->power = 4 + 1;
		wattron(win->big, COLOR_PAIR(abs(tmp->pnum)));
	}
	//	else if (g_var == 0)
	//		data->color = 3;
	if (data->power)
	{
		data->power--;	
		if (!data->power)
			wattroff(win->big, COLOR_PAIR(abs(tmp->pnum)));
	}
}
*/
/*
   void	color_old_pc(t_player *p, t_window *win, t_arena *arena)
   {
   wattron(win, COLOR_PAIR(abs(p->pnum)));
   mvwprintw(win, p->coord[1], p->coord[2], " %.2x", arena->memory[p->oldpc] & 255);
   wattroff(win, COLOR_PAIR(abs(p->pnum)));
   }	
   */
void	ft_update_coord(t_data *data, t_player *player, t_arena *arena, t_window *win)
{
	(void)arena;
	ft_bzero(data, sizeof(data));
	getbegyx(win->big, data->y, data->x);
	data->tmp = data->x + 2;
	data->x += 2;
	while (data->addr <= player->write_addr)
	{
		if (data->x == data->tmp + 64 * 3)
		{
			data->x = data->tmp;
			data->y += 1;
		}
		if (data->addr == player->write_addr) 
			break;
		data->x += 3;
		data->addr += 1;
	}
/*
	*/
}

void	do_movement(t_data *data, t_player *tmp, t_window *win)
{
	(void)win;
	if (MAX_Y == data->y && MAX_X == data->x)
	{
		data->y = 1;
		data->x = 3;	
		tmp->write_addr = 0;
		return ;
	}
	else if (data->x == data->tmp + MAX_X)
	{
		data->x += 2;
		return ;
	}
	tmp->write_addr++;
	data->x += 3;

}

void	change_arena(t_data data, t_player *tmp, t_arena *arena, t_window *win)
{
	
	while (tmp)
	{
		if (tmp->write_bl)
		{
			tmp->write_bl = 0;
			ft_update_coord(&data, tmp, arena, win);
			data.power = 4;
			wattron(win->big, COLOR_PAIR(abs(tmp->pnum)));
			while (data.power)
			{
				mvwprintw(win->big, data.y, data.x, " %.2x", arena->memory[tmp->write_addr] & 255); 
			
				data.power--;
				do_movement(&data, tmp, win); 
				mvwprintw(win->side, debug + 2, 4, "x = %d-%d", data.y, data.x);
				wrefresh(win->side);
				debug++;
	
			}
			wattroff(win->big, COLOR_PAIR(abs(tmp->pnum)));
			tmp->write_addr = 0;
		}
		delete_old(win, arena, tmp);
		color_pc(win, arena, tmp);
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
	change_arena(data, tmp, arena, win);
}
/*
   if (!win->first_round)
   color_old_pc(tmp, win, arena);
   ft_bzero(&data, sizeof(data));
   getbegyx(win, data.y, data.x);
   data.tmp = data.x + 2;
   data.x += 2;
   while (data.addr < MEM_SIZE)
   {
   if (win->first_loop && tmp->pc_inter == data->addr)
   init_print(win, tmp, arena, data);
//	else if (gi_var == 0)
//if (init_print(win, &data, tmp, arena) == 1)
//	break;
data.x += 3;
data.addr += 1;
data.color = 0;
if (data.x == data.tmp + 64 * 3)
{
data.x = data.tmp;
data.y += 1;
}
}
win->first_round = 0;
tmp = tmp->next;
//tmp->oldpc = tmp->pc - tmp->inst->size;
//addr is put to 0 auto
*/
//	}
//	win->first_loop = 0;
