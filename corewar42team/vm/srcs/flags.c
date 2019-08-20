/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:32:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/02/02 11:44:16 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*int		get_flags(t_arena *arena, int *i, t_player *fplayer)*/
int		get_flags(t_arena *arena, int *i) // added
{
	if (ft_strcmp(arena->argv[*i], "-dump") == 0 && arena->argv[*i + 1] &&
	arena->flags->dump_bl == 0)
	{
		if (ft_isdigitstr(arena->argv[*i + 1]) != 1)
			return (print_error(8, NULL, NULL));
		arena->flags->dump_bl = 1;
		arena->flags->dump_cycles = ft_atoi(arena->argv[*i + 1]);
		*i = *i + 1;
		ft_printf("dump after %d\n", arena->flags->dump_cycles);
		return (1);
	}
	else if (ft_strcmp(arena->argv[*i], "-i") == 0)
	{
		arena->flags->interactive = 1;
		ft_printf("entering interactive mode...\n");
		return (1);
	}
	else
		return (-1);
}
