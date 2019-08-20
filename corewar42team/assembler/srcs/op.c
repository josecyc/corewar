/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/01/30 20:36:59 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/assembler.h"

t_op	op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0}, //no
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0}, //yes
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0}, //yes
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0}, //no
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0}, //no
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0}, //no
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0}, //no
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0}, //no
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1}, //yes
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1}, //yes
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1}, //yes
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1}, //yes
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0}, //yes
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1}, //yes
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1}, //yes
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0}, //no
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int		check_index(int op_code)
{
	static int		intarr[6] = {9, 10, 11, 12, 14, 15};
	int				i;

	i = 0;
	while (i < 6)
	{
		if (op_code + 1 == intarr[i])
			return (1);
		i++;
	}
	return (-1);
}
