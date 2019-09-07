/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_informations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:05:34 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/07 14:03:28 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"


void	side_informations(t_window *win, t_arena *arena, t_player *players)
{
	t_player	*tmp;
	t_data		data;

	ft_bzero(&data, sizeof(data));
	tmp = players;
	data.y = 10;
	while (tmp)
	{
		data.x = 2;
		if (!tmp->dead)
		{
			wattron(win->side, COLOR_PAIR(abs(tmp->pnum)));
			mvwprintw(win->side, data.y, data.x, "[%d]\t", tmp->pc); 
			data.x += 9;
			while (tmp->reg[data.power])
			{
				mvwprintw(win->side, data.y, data.x, "%d", tmp->reg); 
				data.power++;
			}
			data.power = 0;
			wattroff(win->side, COLOR_PAIR(abs(tmp->pnum)));
			data.y++;
		}
		tmp = tmp->next;
	}
}
