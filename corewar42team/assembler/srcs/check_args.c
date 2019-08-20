/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:28:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/26 18:52:08 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int	check_arg_type(char **inst, int arg_types, t_vars *ob, int *i)
{
	if (inst[*i][0] == 'r')
	{
		if (check_register(inst[*i], arg_types, ob, *i) == -1)
			return (-1);
		ob->prog_size++;
	}
	else if (inst[*i][0] == DIRECT_CHAR)
	{
		if (check_direct(inst[*i], arg_types, ob, *i) == -1)
			return (-1);
		ob->prog_size += 2;
		if (check_index(ob->op_code) == -1)
			ob->prog_size += 2;
	}
	else
	{
		if (check_indirect(inst[*i], arg_types, ob, *i) == -1)
			return (-1);
		ob->prog_size += 2;
	}
	return (1);
}

int			check_args(int num_args, int *arg_types, char **inst, t_vars *ob)
{
	int i;
	int j;

	ob->prog_size++;
	i = ob->bl_label + 1;
	j = 0;
	op_tab[ob->op_code].encoding_byte == 1 ? ob->prog_size++ : 0;
	while (inst[i] && i < num_args + ob->bl_label + 1)
	{
		if (check_arg_type(inst, arg_types[j], ob, &i) == -1)
			return (-1);
		i++;
		j++;
	}
	if (i != num_args + ob->bl_label + 1 || (inst[i] != NULL && inst[i][0]
				!= COMMENT_CHAR))
		return (error_message(11, ob->counter, 0));
	return (1);
}
