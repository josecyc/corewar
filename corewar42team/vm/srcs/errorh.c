/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:39:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/09 10:52:06 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		print_error(int errnum, t_player *fplayer, t_arena *arena)
{
	if (errnum == 1)
		ft_printf("invalid program size read --> Refusing the compilation \n");
	else if (errnum == 2)
		ft_printf("invalid flag \n");
	else if (errnum == 3)
		ft_printf("invalid program file\n");
	else if (errnum == 4)
		ft_printf("too many gladiators, max number allowed is %d you have %d\n",
MAX_PLAYERS, arena->num_plys);
	else if (errnum == 5)
		ft_printf("unable to open program file\n");
	else if (errnum == 6)
		ft_printf("File not Conform\n");
	else if (errnum == 7)
		ft_printf("%s", OPTIONS);
	else if (errnum == 8)
		ft_printf("Options -dump Must be followed by a number: ./corewar \
				[-dump] [num cycles till dump] [[champions.cor]...]\n");
	else if (errnum == 9)
		ft_printf("player number '%d' previously assigned\n", fplayer->pnum);
	else if (errnum == 10)
		ft_printf(" Options -n Must be followed by a number: ./corewar\
				[-n] [number] \n");
	return (-1);
}
