/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_are_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:38:38 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/07 12:11:32 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		delete_old(t_window *win, t_arena *arena, t_player *tmp)
{
	t_data data;

	ft_bzero(&data, sizeof(data));
	tmp->write_addr = tmp->oldpc;
	ft_update_coord(&data, tmp, arena, win);
	data.color = 3;
	wattron(win->big, COLOR_PAIR(abs(tmp->pnum)));
	print_color(win, tmp, arena, data);
	wattroff(win->big, COLOR_PAIR(abs(tmp->pnum)));
}

void		color_pc(t_window *win, t_arena *arena, t_player *tmp)
{
	t_data data;

	ft_bzero(&data, sizeof(data));
	tmp->write_addr = get_addr_value(tmp, (-tmp->inst->size));
	tmp->oldpc = tmp->write_addr;
	ft_update_coord(&data, tmp, arena, win);
	data.color = 1;
	wattron(win->big, COLOR_PAIR(abs(tmp->pnum)));
	print_color(win, tmp, arena, data);
	wattroff(win->big, COLOR_PAIR(abs(tmp->pnum)));
}
