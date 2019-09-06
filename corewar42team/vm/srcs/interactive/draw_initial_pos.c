/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_initial_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:49:55 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/05 17:17:57 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	print_color(WINDOW *big_win, t_player *p, t_arena *arena, t_data data)
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

	else if (data.color == 3)
		mvwprintw(big_win, data.y, data.x, " %.2x", arena->memory[data.addr] & 255);
}

void	tag_pc(t_player *tmp, t_data *data, WINDOW *win)
{
	if (get_addr_value(tmp, (-tmp->inst->size)) == data->addr)
	{
		data->color = 1; // couleur de marquage
		tmp->coord[1] = data->y;
		tmp->coord[2] = data->x;
		if (g_var == 0)
		{
			endwin();
			data->power = tmp->prog_size;
			ft_putnbr(abs(tmp->pnum));
			wattron(win, COLOR_PAIR(abs(tmp->pnum)));
		}
	}
	else if (g_var == 0)
		data->color = 3;
	data->power--;
	if (!data->power)
			wattroff(win, COLOR_PAIR(abs(tmp->pnum)));
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
	tmp = p;
	
	while (tmp)
	{
		ft_bzero(&data, sizeof(data));
		getbegyx(big_win, data.y, data.x);
		data.tmp = data.x + 2;
		data.x += 2;
		while (data.addr < MEM_SIZE)
		{
			if (data.x == data.tmp + 64 * 3)
			{
				data.x = data.tmp;
				data.y += 1;
			}
			tag_pc(tmp, &data, big_win);
			print_color(big_win, tmp, arena, data);
			data.x += 3;
			data.addr += 1;
			data.color = 0;
		}
		tmp->oldpc = tmp->pc - tmp->inst->size;
		tmp = tmp->next;
		i++;
	}
}
