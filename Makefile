# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viclucas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 15:19:32 by viclucas          #+#    #+#              #
#    Updated: 2019/09/10 15:22:08 by viclucas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = compile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
LIBFT =	-L./libft -lft

LIBFT_PATH = ./libft
VM_PATH	= ./vm
ASM_PATH = ./assembler

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@make -C $(VM_PATH)
	@make -C $(ASM_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(VM_PATH) clean
	@make -C $(ASM_PATH) clean

fclean:	clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(VM_PATH) fclean
	@make -C $(ASM_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re
