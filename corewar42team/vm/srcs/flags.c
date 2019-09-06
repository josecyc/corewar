/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:32:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/05 22:57:28 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		get_flags(t_arena *arena, int *i, t_player **fplayer)
{
	if (ft_strcmp(arena->argv[*i], "-dump") == 0 && arena->argv[*i + 1] &&
	arena->flags->dump_bl == 0)
	{
		if (ft_isdigitstr(arena->argv[*i + 1]) != 1)
			return (print_error(8, *fplayer, arena));
		arena->flags->dump_bl = 1;
		arena->flags->dump_cycles = ft_atoi(arena->argv[*i + 1]);
		*i = *i + 2;
		//ft_printf("dump after %d\n", arena->flags->dump_cycles);
		//ft_printf("index %d\n", *i);
		return (1);
	}
	else if (ft_strcmp(arena->argv[*i], "-i") == 0)
	{
		arena->flags->interactive = 1;
		ft_printf("entering interactive mode...\n");
		return (1);
	}
	else
		return (0);
}
