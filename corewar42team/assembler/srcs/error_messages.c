/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:50:23 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/10 14:05:22 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int			error_message_pt2(int msg_nb, int i, int arg)
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
	else if (msg_nb == 13)
		printf("Error, no program code\n");
	return (-1);
}

int			error_message(int msg_nb, int i, int arg)
{
	if (msg_nb == 0)
		printf("Incorrect number of arguments\nUSAGE: ./asm [file.s]\n");
	else if (msg_nb == 1)
		printf("Error in the input file\nUSAGE: ./asm [file.s]\n");
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
