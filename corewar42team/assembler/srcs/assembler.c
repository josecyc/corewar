/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:09:01 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/26 17:10:46 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int				get_op(char *mnemonic, t_vars *ob)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(op_tab[i].mnemonic, mnemonic) == 0)
		{
			ob->op_code = i;
			return (i);
		}
		i++;
	}
	return (error_message(6, ob->counter, 0));
}

int				free_split(char **inst)
{
	int	i;

	i = 0;
	if (inst)
	{
		while (inst[i])
		{
			free(inst[i]);
			i++;
		}
		free(inst);
	}
	return (0);
}

static char		*set_output_name(char *old_name)
{
	char	*new_name;
	size_t	len;

	len = ft_strlen(old_name);
	new_name = (char *)malloc(sizeof(char) * (len + 3));
	if (!new_name)
		return ("ERROR");
	ft_strncpy(new_name, old_name, len - 1);
	new_name[len - 1] = '\0';
	ft_strcat(new_name, "cor");
	return (new_name);
}

static void		init_vars(t_vars *ob)
{
	ob->output_fd = -1;
	ob->player_name = NULL;
	ob->comment = NULL;
	ob->labels = NULL;
	ob->bl_label = 0;
	ob->op_code = 0;
	ob->begin_line = 0;
	ob->counter = 0;
	ob->prog_size = 0;
}

int				main(int argc, char **argv)
{
	t_vars	ob;
	int		fd;

	init_vars(&ob);
	if (argc != 2)
		return (error_message(0, 0, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !ft_strequ(argv[1] + ft_strlen(argv[1]) - 2, ".s"))
		return (error_message(1, 0, 0));
	if (lexer(&ob, fd) == -1)
		return (-1);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	get_label_address(&ob, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	ob.output_fd = open(set_output_name(argv[1]),
						O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (generator(&ob, fd) == -1)
		return (-1);
	close(fd);
	close(ob.output_fd);
	return (0);
}
