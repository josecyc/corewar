/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:58:22 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/09 14:42:08 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		announce_winner(t_arena *arena, t_player *fplayer)
{
	// Check the corresponding player name to the last alive value
	//ft_printf("\n\nPlayer %d won\n", arena->last_alive);
}

static int		get_args(t_arena *arena, t_player **fplayer)
{
	int i;

	i = 1;
	while (arena->argv[i])
	{
		if (get_flags(arena, &i, fplayer) == -1)
			return(-1);
		if(get_player(arena, fplayer, &i) == -1)
				return (-1);
		else
			i++;
	}
	return (1);
}

static int		init_state(t_arena *arena, t_player **fplayer)
{
	if (arena->argc == 1)
		return (print_error(7, *fplayer, arena));
	if (get_args(arena, fplayer) == -1)
		return (-1);
	//ft_printf("\n\ninitializing ARENA\n\nfplayer->next->name %s\n", (*fplayer)->name);
	if (init_arena(arena, fplayer) == -1)
		return (-1);
	return (1);
}

int		main(int argc, char **argv)
{
	t_arena		arena;
	t_player	*fplayer;
	t_window		win;

//	printf("Introducing contestants...\n* Player 1, weighing 670 bytes, \"King Sombra\" (\"Crystal empire is mine!\") !\n");
	init_arena_ob(&arena, argc, argv);
	init_interactive_mode(&win);
	fplayer = NULL;
	if (init_state(&arena, &fplayer) == -1)
		return (-1);
	loop(fplayer, &arena);
	//print_info(&arena, fplayer);
	//print_memory(arena.memory);
	//announce_winner(&arena, fplayer);
//	system("leaks corewar");
	winner_print(fplayer, &arena, &win);
	//close_win();
	return (0);
}
