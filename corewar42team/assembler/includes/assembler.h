/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:15:46 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/30 15:52:56 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

#include "op.h"
#include "../../libft/libft.h"
#include <stdio.h>

typedef struct			s_op
{
	char				*mnemonic;
	int					num_args;
	int					arg_types[3];
	int					op_code;
	int					num_cycles;
	char				*description;
	int					encoding_byte;   //boolean
	int					carry;
}						t_op;

extern t_op		op_tab[17];

typedef struct			s_label
{
	char				*label;
	int					address;
	struct s_label		*next;
}						t_label;

typedef struct			s_param
{
	int					value;
	int					type;
	int					index;
	int					size;   //neccesary?
	struct	s_param		*next;
}						t_param;

typedef struct			s_ins
{
	int					op_code;
	int					arg_types[3];
	int					encoding_value;
	t_param				*params;
	struct s_ins		*next;
}						t_ins;	


typedef struct			s_vars
{
	int					output_fd;
	char				*player_name;
	char				*comment;
	t_label				*labels;
	int					bl_label;
	int					op_code;
	int					begin_line;
	int					counter;
	int					prog_size;
}						t_vars;

/*
**	assembler
*/
int		get_op(char *mnemonic, t_vars *ob);
int		free_split(char **inst);

/*
**	check_arg_types
*/
int		check_register(char *reg, int arg_types, t_vars *ob, int arg);
int		check_direct(char *direct, int arg_types, t_vars *ob, int arg);
int		check_indirect(char *ind, int arg_types, t_vars *ob, int arg);

/*
** check_args
*/
int		check_args(int num_args, int *arg_types, char **inst, t_vars *ob);

/*
**	error_messages
*/
int		error_message(int msg_nb, int i, int inst);

/*
**	generator
*/
int		generator(t_vars *ob, int fd);

/*
**	get_name
*/
int		check_name(t_vars *ob, char *line);

/*
**	lexer
*/
int		lexer(t_vars *ob, int fd);

/*
** op
*/
int		check_index(int op_code);

/*
** parser
*/
int		get_label_address(t_vars *ob, int fd);

/*
** print
*/
int		print_direct(char *param, t_vars *ob, int begin_address, int arg);
int		print_indirect(char *param, t_vars *ob, int begin_address, int arg);

/*
** tools
*/
void	byte_print(int nb, int byte, int fd);
int		all_whitespace(char *line);
int		power_of2(int exp);

#endif
