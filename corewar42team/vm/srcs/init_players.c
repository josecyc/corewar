/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:16:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/01 16:37:47 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		assign_number(t_player *fplayer, int cur_pl_num)
{
	t_player	*cur;
	int			i;

	cur = fplayer->next;
	fplayer->pnum = cur_pl_num;
	while (cur && cur_pl_num != 0)
	{
		if (cur->pnum == cur_pl_num)
			return (print_error(9, fplayer, NULL));
		cur = cur->next;
	}
	i = -1;
	while (cur && cur_pl_num == 0)
	{
		if (cur->pnum == i && --i)
			cur = fplayer;
		cur = cur->next;
	}
	if (cur_pl_num == 0)
		fplayer->pnum = i;
	fplayer->reg[0] = fplayer->pnum;
	return (1);
}

t_inst		*init_instruction(void)
{
	t_inst	*new_inst;
	int		i;

	if (!(new_inst = (t_inst *)malloc(sizeof(t_inst))))
		exit (1);
	new_inst->counter = -1;
	new_inst->op_code = -1;
	new_inst->ebyte = 0;
	i = 0;
	while (i < 3)
		new_inst->args[i++] = 0;
	return (new_inst);
}

t_player	*create_player(void)
{
	t_player	*player;
	t_inst		*inst;
	int			i;

	if (!(player = (t_player*)malloc(sizeof(t_player))))
		exit (1);
	i = 0;
	ft_bzero(&(*player), sizeof(t_player));
	while (i < REG_NUMBER)
		player->reg[i++] = 0;
	inst = init_instruction();
	player->inst = inst;
	return (player);
}

t_player	*add_player(t_player **head)
{
	t_player	*elem;

	elem = create_player();
	elem->next = *head;
	return (elem);
}

int		init_player(int fd, t_arena *arena, t_player **fplayer)
{
	char	buf;
	char	program[PROG_MAX_SIZE];
	int		j;

	j = 0;
	while (read(fd, &buf, 1) > 0) // READ AND PUT IN PROGRAM;
	{
		program[j++] = buf;
		if(j == PROG_MAX_SIZE - 1)    /// CHECK IF PROG TO BIG in verify prog?
			return (print_error(1, *fplayer, arena));
	}
	close(fd);
	*fplayer = add_player(fplayer);
	if (verify_program(fplayer, program, j) == -1)
		return (print_error(3, *fplayer, arena));
	return (1);
}