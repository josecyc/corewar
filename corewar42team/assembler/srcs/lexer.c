/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:28:59 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/26 19:11:34 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static t_label	*ft_create_elem(char *lbl)
{
	t_label	*elem;

	elem = (t_label*)malloc(sizeof(t_label));
	elem->label = ft_strdup(lbl);
	elem->address = -1;
	elem->next = NULL;
	return (elem);
}

static int		check_label(char *lbl, t_vars *ob)
{
	int		i;

	i = 0;
	while (lbl[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, lbl[i]))
			return (error_message(4, ob->counter, 0));
		i++;
	}
	if (lbl[i + 1] != '\0' || lbl[0] == LABEL_CHAR)
		return (error_message(5, ob->counter, 0));
	return (1);
}

static int		get_label(char *lbl, t_vars *ob)
{
	t_label	*tmp;
	t_label	*elem;

	tmp = ob->labels;
	while (tmp && tmp->next)
	{
		if (ft_strcmp(lbl, tmp->label) == 0)
			return (error_message(3, ob->counter, 0));
		tmp = tmp->next;
	}
	if (tmp && ft_strcmp(lbl, tmp->label) == 0)
		return (error_message(3, ob->counter, 0));
	if (check_label(lbl, ob) == -1)
		return (-1);
	elem = ft_create_elem(lbl);
	if (ob->labels == NULL)
		ob->labels = elem;
	if (tmp != NULL)
		tmp->next = elem;
	ob->bl_label = 1;
	return (0);
}

static int		arg_lexer(char **inst, t_vars *ob)
{
	if (ft_strchr(inst[0], LABEL_CHAR) && get_label(inst[0], ob) == -1)
		return (-1);
	if (inst[ob->bl_label] && inst[ob->bl_label][0] != COMMENT_CHAR
			&& (get_op(inst[ob->bl_label], ob) == -1 ||
			check_args(op_tab[ob->op_code].num_args,
			op_tab[ob->op_code].arg_types, inst, ob) == -1))
		return (-1);
	return (1);
}

int				lexer(t_vars *ob, int fd)
{
	char	*line;
	char	**inst;

	while ((get_next_line(fd, &line) > 0))
	{
		inst = ft_strsplit(line, " ,\t");
		ob->counter++;
		ob->bl_label = 0;
		if (inst[0] && (ft_strcmp(inst[0], NAME_CMD_STRING) == 0 ||
				ft_strcmp(inst[0], COMMENT_CMD_STRING) == 0))
		{
			if (check_name(ob, line) == -1)
				return (-1);
		}
		else if (all_whitespace(line) == 0 && inst[0][0] != COMMENT_CHAR)
			if (arg_lexer(inst, ob) == -1)
				return (-1);
		free_split(inst);
		free(line);
	}
	return (1);
}
