/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_management.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:36:43 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/09 21:34:25 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	rewrite_pc(t_player *tmp, t_arena *arena, t_window *win)
{
	t_data data;

	ft_bzero(&data, sizeof(data));
	tmp->oldpc = get_addr_value(tmp, (-tmp->inst->size));
	ft_update_coord(&data, tmp->oldpc, win->big);
	if (win->tab[tmp->oldpc] == abs(tmp->pnum))
	{
		data.color = 1;
		wattron(win->big, COLOR_PAIR(abs(tmp->pnum)));
		print_color(win, arena, data);
		wattroff(win->big, COLOR_PAIR(abs(tmp->pnum)));
	}
	else
	{
		data.color = 3;
		wattron(win->big, COLOR_PAIR(win->tab[tmp->oldpc]));
		print_color(win, arena, data);
		wattroff(win->big, COLOR_PAIR(win->tab[tmp->oldpc]));
	}
}

void	change_pc(t_data data, t_player *tmp, t_arena *arena, t_window *win)
{
	while (tmp)
	{
		ft_bzero(&data, sizeof(data));
		data.addr = 0;
		ft_update_coord(&data, tmp->oldpc, win->big);
		data.color = 3;
		wattron(win->big, COLOR_PAIR(win->tab[tmp->oldpc]));
		print_color(win, arena, data);
		wattroff(win->big, COLOR_PAIR(win->tab[tmp->oldpc]));
		rewrite_pc(tmp, arena, win);
		tmp = tmp->next;
	}
}
