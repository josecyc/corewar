/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:39:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/10 17:12:37 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_error_expend(int errnum, t_player *fplayer, t_arena *arena)
{
	if (errnum == 8)
	{
		ft_printf("Option -dump must be followed by a number and without -i");
		ft_printf(" flag:\n./corewar [-dump] [num cycles till dump]");
		ft_printf(" [champions.cor]...]\n");
	}
	else if (errnum == 7)
	{
		ft_printf("USAGE ./corewar:\n-i for interactive mode (mutually");
		ft_printf("exclusive with -dump flag) \n-n [desired_player_num]");
		ft_printf("[player]\n-dump [cycles] [player] for ");
		ft_printf("dumping arena memory\n");
	}
	else if (errnum == 10)
	{
		ft_printf("Option -n Must be followed by a number:\n");
		ft_printf("./corewar [-n] [number] \n");
	}
}

int		print_error(int errnum, t_player *fplayer, t_arena *arena)
{
	if (errnum == 1)
		ft_printf("invalid program size read --> Refusing the compilation \n");
	else if (errnum == 2)
		ft_printf("invalid flag \n");
	else if (errnum == 3)
		ft_printf("invalid program file\n");
	else if (errnum == 4)
		ft_printf("too many gladiators\n");
	else if (errnum == 5)
		ft_printf("unable to open program file\n");
	else if (errnum == 6)
		ft_printf("File not Conform\n");
	else if (errnum == 9)
		ft_printf("player number '%d' previously assigned\n", fplayer->pnum);
	print_error_expend(errnum, fplayer, arena);
	return (-1);
}

int		print_error2(int errnum, t_player *fplayer, t_arena *arena)
{
	if (errnum == 1)
	{
		ft_printf("No players to play, get some bloody ");
		ft_printf("gladiators in the arena!\n");
	}
	if (errnum == 2)
		ft_printf("Option -i for interactive mode can must only be set once\n");
	return (-1);
}
