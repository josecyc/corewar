/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:22:58 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/08/29 11:10:24 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** This function forks a process by adding a player to the list with the 
** same id of the one who executes it
** No parameter encoding byte
** Takes an index
** creates a new program which is executed from PC + first param % IDX_MOD
** Program inherits all of its father states (registers only) not program
*/

void    fork(t_player *player, t_arena *arena)
{

}
