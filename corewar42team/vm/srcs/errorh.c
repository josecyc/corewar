/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:39:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/02/02 16:06:41 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		print_error(int errnum, t_player *fplayer, t_arena *arena)
{
	if (errnum == 1)
		ft_printf("invalid program size read %d but got %d, max size is %d\n",
	fplayer->prog_size, fplayer->actual_size, CHAMP_MAX_SIZE);
	else if (errnum == 2)
		ft_printf("invalid flag \n");
	else if (errnum == 3)
		ft_printf("invalid program file\n");
	else if (errnum == 4)
		ft_printf("too many gladiators, max number allowed is %d you have %d\n",
MAX_PLAYERS, arena->num_plys);
	else if (errnum == 5)
		ft_printf("unable to open %s program file\n", fplayer->name);
	else if (errnum == 6)
		ft_printf("error in magic number");
	else if (errnum == 7)
		ft_printf("%s", OPTIONS);
	else if (errnum == 8)
		ft_printf("invalid -dump, format is: -dump [num cycles till dump]\n");
	else if (errnum == 9)
		ft_printf("player number '%d' previously assigned\n", fplayer->pnum); // added
	return (-1);
}
