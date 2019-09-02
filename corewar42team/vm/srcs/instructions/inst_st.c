/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:21:56 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 12:03:12 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**  Op Code number 3;
**  Change the carry if the first argument is egal to 0;
**  Write the first argument into th
 */
static void         inst_st(t_player *cur, t_arena *arena)
{
    char arg_type;
    arg_type = cur->inst->ebyte >> 6 & 3;
    arg_type = cur->inst->ebyte >> 4 & 3;

    if(arg_type == IND_CODE)
        arena->memory[(cur->pc - 3) + (cur->inst->args[1] % IDX_MOD)] = (char)cur->inst->args[0];    /// - 3 (T_IND + T_REG)  
    else
        arena->memory[(cur->pc - 2)] = (char)cur->inst->args[0];
}