/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:29:05 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/26 19:12:38 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int		count_params(int op_code, int num_args, char **inst, int bl)
{
	int	mem;
	int i;

	i = 1 + bl;
	mem = 0;
	while (i < num_args + 1 + bl)
	{
		if (inst[i][0] == 'r')
			mem++;
		else if (inst[i][0] == DIRECT_CHAR && check_index(op_code) != 1)
			mem += DIR_SIZE;
		else
			mem += IND_SIZE;
		i++;
	}
	return (mem);
}

static int		set_address(char *label, int address, t_vars *ob)
{
	t_label *tmp;

	tmp = ob->labels;
	ob->bl_label = 1;
	while (tmp)
	{
		if (ft_strcmp(tmp->label, label) == 0)
		{
			tmp->address = address;
			return (1);
		}
		tmp = tmp->next;
	}
	return (-1);
}

static int		count_bytes(char **inst, t_vars *ob)
{
	int		counter;

	counter = 0;
	get_op(inst[ob->bl_label], ob);
	counter += 1 + op_tab[ob->op_code].encoding_byte;
	counter += count_params(ob->op_code, op_tab[ob->op_code].num_args,
			inst, ob->bl_label);
	return (counter);
}

/*
** Second pass through the file. Will check validity of all labels used and
** get addresses for each label. Uses counter to keep track of current address
*/

int				get_label_address(t_vars *ob, int fd)
{
	int		counter;
	char	*line;
	char	**inst;

	counter = 2192;
	skip_lines(ob->begin_line, fd);
	while ((get_next_line(fd, &line) > 0))
	{
		ob->bl_label = 0;
		inst = ft_strsplit(line, " ,\t");
		if (inst[0] && inst[0][0] != COMMENT_CHAR && inst[0][0] != '.' &&
				!all_whitespace(line))
		{
			if (ft_strchr(inst[0], LABEL_CHAR))
				set_address(inst[0], counter, ob);
			if (ob->bl_label != 1 || (inst[1] && inst[1][0] != COMMENT_CHAR))
				counter += count_bytes(inst, ob);
		}
		free_split(inst);
		free(line);
	}
	return (1);
}
