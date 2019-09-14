/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2019/09/10 18:53:16 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				6
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_NUMBER				16
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
** T_REG identifier for register parameter takes only 1 byte
** T_DIR identifier for direct parameter as many as specified in label_size
** command? or 4 bytes depending on index
** T_IND identifier for indirect parameter 2 bytes
** T_LAB identifier for label parameter?
*/

typedef char			t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
# define PROG_NAME_LENGTH		(128)
# define C_L					(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
# define PROG_MAX_SIZE			(C_L + PROG_NAME_LENGTH + 17 + CHAMP_MAX_SIZE)

#endif
