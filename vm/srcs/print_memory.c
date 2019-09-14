/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:01:01 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/09 11:06:58 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_memory(char memory[MEM_SIZE])
{
	int		addr;

	addr = 0;
	printf("0x");
	while (addr < MEM_SIZE)
	{
		if (addr % 64 == 0)
			printf("%#.4x :", addr);
		printf(" %.2x", memory[addr] & 255);
		if ((addr + 1) % 64 == 0)
			printf(" \n");
		addr++;
	}
}
