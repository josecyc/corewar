/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:22:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 12:39:55 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/* 
**	opcode 0x0d, changes carry
**  usage : lld ARG_1(ID/D4), ARG_2(RG)
**	same as load but without % IDX_MOD
**	loads the value of ARG_1 in ARG_2
*/

void		inst_lld(t_player *cur, t_arena *arena)
{

    (void) cur;
    (void) arena;

}