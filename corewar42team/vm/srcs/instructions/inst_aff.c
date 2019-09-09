/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:27:56 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/09 13:22:21 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**ft_aff
**opcode 0x10 --> N°16
**usage : aff ARG_1(RG)
**displays the character of which the ASCII code (%256) is stored in ARG_1
*/

void		inst_aff(t_player *cur, t_arena *arena)
{
	unsigned char c;

	(void)arena;
	c = ((unsigned char)cur->inst->args[0] % 256);
	write(1, &c, 1);
}
