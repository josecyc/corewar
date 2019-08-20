/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:45:01 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/30 10:19:02 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int		check_max_sizes(t_vars *ob)
{
	if (ob->player_name && ft_strlen(ob->player_name) > 128)
	{
		printf("Champion Name too long (Max length 128)\n");
		return (-1);
	}
	if (ob->comment && ft_strlen(ob->comment) > 2048)
	{
		printf("Comment too long (Max length 2048)\n");
		return (-1);
	}
	return (1);
}

static void		save_name_comment(t_vars *ob, char i, char *new)
{
	if (i == 'n')
		ob->player_name = new;
	else
		ob->comment = new;
	ob->begin_line = ob->counter;
}

int				check_name(t_vars *ob, char *line)
{
	char	i;
	char	*new;

	line = ft_strchr(line, '.');
	i = *(++line);
	while (*line && *line != ' ' && *line != '\t')
		line++;
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line != '"')
		return (error_message(2, i, 0));
	line++;
	if (!ft_strchr(line, '"') || ft_strchr(line, '"') != ft_strrchr(line, '"'))
		return (error_message(2, i, 0));
	new = ft_strdup(line);
	line = ft_strchr(new, '"');
	*line = '\0';
	while (*(++line))
		if (*line != ' ' && *line != '\t')
			return (error_message(2, i, 0));
	save_name_comment(ob, i, new);
	return (check_max_sizes(ob));
}
