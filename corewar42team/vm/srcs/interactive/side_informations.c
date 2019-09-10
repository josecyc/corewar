/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_informations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:05:34 by viclucas          #+#    #+#             */
/*   Updated: 2019/09/09 16:32:31 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"


void	basic_infos(t_window *win, t_data data, t_player *tmp)
{
	t_data	tmp_data;	

	ft_bzero(&tmp_data, sizeof(tmp_data));
	ft_update_coord(&tmp_data, get_addr_value(tmp, (-tmp->inst->size)), win->side);
	mvwprintw(win->side, data.y, data.x, "[%d][%d] ", tmp_data.y, tmp_data.x / (64 * 3) + 2); 


}

void	side_informations(t_window *win, t_player *players)
{
	t_player	*tmp;
	t_data		data;

	ft_bzero(&data, sizeof(data));
	tmp = players;
	data.y = 1;
	while (tmp)
	{
		data.x = 2;
		if (!tmp->dead)
		{
			wattron(win->side, COLOR_PAIR(abs(tmp->pnum)));
			basic_infos(win, data, tmp);
			data.x += 11;
			mvwprintw(win->side, data.y, data.x, "%s         ", tmp->name); 
			data.x = data.x + ft_strlen(tmp->name) + 9;
			mvwprintw(win->side, data.y, data.x, "         "); 
			wattroff(win->side, COLOR_PAIR(abs(tmp->pnum)));
			data.y++;
		}
		tmp = tmp->next;
	}
}
