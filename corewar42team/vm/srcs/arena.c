/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:48:07 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/10 12:51:33 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		welcome_msg(t_arena *arena, t_player **fplayer)
{
	t_player	*cur;

	cur = *fplayer;
	ft_printf("|| ================= WELCOME TO THE JUNGLE ================= ||\n");
	ft_printf("||                                                           ||\n");
	ft_printf("||       Get ready to presence the legendary gladiator       ||\n");
	ft_printf("||               FIGHT FOR THE COOOORE!!!!!                  ||\n");
	ft_printf("||                                                           ||\n");
	ft_printf("||                                                           ||\n");
	while (cur)
	{
		ft_printf("|| Introducing \"%s\"\n", cur->name);
		ft_printf("|| Any comment?: \"%s\"\n", cur->comment);
		cur = cur->next;
	}
	ft_printf("||                                                           ||\n");
	ft_printf("|| ============= MAY THE CODE BE WITH YOU ALL ============== ||\n");
}

static int		write_player(t_arena *arena, t_player *elem)
{
	int		i;
	int		pc_counter;

	i = 0;
	pc_counter = elem->pc;
	while (i < elem->prog_size)
	{
		arena->memory[pc_counter] = elem->prog[i++];
		pc_counter++;
	}
	return (1);
}

static int		get_numplys(t_arena *arena, t_player **fplayer)
{
	int			num;
	t_player	*elem;

	num = 0;
	elem = *fplayer;
	while (elem)
	{
		elem = elem->next;
		num++;
	}
	arena->num_plys = num;
	if (num > 4 || num > MAX_PLAYERS)
		return (-1);
	return (num);
}

int				init_arena(t_arena *arena, t_player **fplayer)
{
	int			i;
	t_player	*elem;

	if (get_numplys(arena, fplayer) == -1)
		return (print_error(4, *fplayer, arena));
	if (!arena->flags->interactive)
		welcome_msg(arena, fplayer);
	i = arena->num_plys;
	elem = *fplayer;
	while (i > 0)
	{
		elem->pc = (i - 1) * (MEM_SIZE / arena->num_plys);
		elem->pc_inter = elem->pc;
		write_player(arena, elem);
		elem = elem->next;
		i--;
	}
	return (1);
}
