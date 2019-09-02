/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:27:39 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 12:39:40 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/* 
**	opcode 0x04, changes carry if the result is null
**	usage : add ARG_1(RG), ARG_2(RG), ARG_3(RG), key 54
**	adds the value in ARG_1 to the value in ARG_2 and puts it in ARG_3
*/

void		inst_add(t_player *cur, t_arena *arena)
{
    (void) cur;
    (void) arena;
}