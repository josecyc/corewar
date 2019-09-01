/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:16:48 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/01 12:43:28 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Validate and fill the player data and check the -n flag
*/

static int		check_size(t_player **fplayer, char *prog)
{
	int		i;
	int		addr;
	int		actual_size;

	i = 0;
	addr = COMMENT_LENGTH + PROG_NAME_LENGTH + 16;
	actual_size = (*fplayer)->total_size - PROG_NAME_LENGTH - 16 -
	COMMENT_LENGTH;
	ft_printf("actual weight: %d bytes\n", actual_size);
	ft_printf("total weight: %d bytes\n\n", (*fplayer)->total_size);
	if (!((*fplayer)->prog = (char *)malloc(sizeof(char) * actual_size)))
		exit (1);
	ft_printf("instruction program\n");
	while (i < actual_size)
	{
		(*fplayer)->prog[i++] = prog[addr++];
		ft_printf("%.2x ", (*fplayer)->prog[i - 1]);
	}
	ft_printf("\n");
	return (1);
}

int		verify_program(t_player **fplayer, char *prog, int size)
{
	int		magic;

	magic = 0xf383ea00;
	if (ft_memcmp(prog, &magic, 4) != 0)
		return (-1);
	(*fplayer)->name = ft_strdup(prog + 4);
	mem_to_int(&(*fplayer)->prog_size, 136, prog, 4);
	(*fplayer)->comment = ft_strdup(prog + 128 + 12);
	(*fplayer)->total_size = size;
	ft_printf("in this corner we have: %s\n", (*fplayer)->name);
	ft_printf("comment?: %s\n", (*fplayer)->comment);
	if (check_size(fplayer, prog) == -1)
		return (-1);
	return (0);
}

static int		check_openfile(t_arena *arena, t_player **fplayer, int i)
{
	int fd;

	fd = 0;
	if ((fd = open(arena->argv[i], O_RDONLY)) == -1) //// FAIL OPEN 
	{
		if(!ft_strequ("-dump", arena->argv[i]) && \
		!ft_strequ("-i", arena->argv[i]) && !ft_strequ("-n", arena->argv[i]))
		{
			if(arena->argv[i][0] == '-')
				return(print_error(2, *fplayer, arena)); /// FLAGS ERROR 
			else 
				return (print_error(5, *fplayer, arena)); /// PROGRAM ERROR 
		}
		return(-1);
	}
	if(init_player(fd, arena, fplayer) == -1)
			return(-1);
	return(0);
}

int		get_player(t_arena *arena, t_player **fplayer, int *i)
{
	int		cur_pl_num;

	cur_pl_num = 0;
	if (ft_strcmp(arena->argv[*i], "-n") == 0)
	{
		if (!arena->argv[*i + 1] || ft_isdigitstr(arena->argv[*i + 1]) == -1)
			return (print_error(10, *fplayer, arena));		
		else if(!arena->argv[*i + 2])
			return (print_error(10, *fplayer, arena));
		else
		{
			cur_pl_num = ft_atoi(arena->argv[*i + 1]);
			*i = *i + 2;
		}
	}
	if (check_openfile(arena, fplayer, *i) == -1)
		return(-1);	
	if (assign_number(*fplayer, cur_pl_num) == -1)
		return (-1);
	return (1);
}
