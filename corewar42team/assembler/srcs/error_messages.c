/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:50:23 by tholzheu          #+#    #+#             */
/*   Updated: 2019/01/26 18:37:57 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static void			error_message_pt2(int msg_nb, int i, int arg)
{
	if (msg_nb == 9)
	{
		printf("Error on line %d, argument %d: ", i, arg);
		printf("register number out of range\n");
	}
	else if (msg_nb == 10)
	{
		printf("Error on line %d, argument %d: ", i, arg);
		printf("invalid characters in label\n");
	}
	else if (msg_nb == 11)
	{
		printf("Error on line %d: ", i);
		printf("the number of arguments don't match with the expected\n");
	}
	else if (msg_nb == 12)
		printf("Error on line %d, argument %d: no such label\n", i, arg);
}

int					error_message(int msg_nb, int i, int arg)
{
	if (msg_nb == 0)
		printf("Incorrect number of arguments\nusage ./asm [file.s]\n");
	else if (msg_nb == 1)
		printf("Error in the input file\nusage ./asm [file.s]\n");
	else if (msg_nb == 2 && i == 'n')
		printf("Lexical error in name\n");
	else if (msg_nb == 2)
		printf("Lexical error in comment\n");
	else if (msg_nb == 3)
		printf("Error on line %d: label was used before\n", i);
	else if (msg_nb == 4)
		printf("Error on line %d: invalid characters in label\n", i);
	else if (msg_nb == 5)
		printf("Error on line %d: lexical error in label\n", i);
	else if (msg_nb == 6)
		printf("Error on line %d: syntax error in mnemonic\n", i);
	else if (msg_nb == 7)
	{
		printf("Error on line %d, argument %d: ", i, arg);
		printf("invalid argument type\n");
	}
	else if (msg_nb == 8)
		printf("Error on line %d, argument %d: syntax error\n", i, arg);
	error_message_pt2(msg_nb, i, arg);
	return (-1);
}
