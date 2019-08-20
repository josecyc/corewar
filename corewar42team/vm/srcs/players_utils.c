/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:16:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/02/02 16:46:13 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_inst		*init_instruction(void) // added
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
	while (i < REG_NUMBER)
		player->reg[i++] = 0;
	player->name = NULL;
	player->comment = NULL;
	player->pnum = 0;
	player->dead = 0;
	player->carry = 0;
	player->life_bl = 0;
	inst = init_instruction();
	player->inst = inst;
	player->prog = NULL;
	player->prog_size = 0;
	player->total_size = 0;
	player->first = 0;
	player->next = NULL;
	return (player);
}

t_player	*add_player(t_player **head)
{
	t_player	*elem;

	elem = create_player();
	elem->next = *head;
	return (elem);
}
