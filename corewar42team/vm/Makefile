# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 19:22:08 by jdiaz             #+#    #+#              #
#    Updated: 2019/08/29 11:10:43 by jcruz-y-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

### PATH ###
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = ../libft/

FLAGS = -Wall -Werror -Wextra -g

INC = -I ./includes/ -I ./$(LIBFT_PATH)

VM_SRC	= srcs/errorh.c \
		  srcs/flags.c \
		  srcs/init_objs.c \
		  srcs/init_players.c \
		  srcs/players.c \
		  srcs/vm.c \
		  srcs/arena.c \
		  srcs/print_memory.c \
		  srcs/live_checkup.c \
		  srcs/loop.c \
		  srcs/save_inst.c \
		  ../assembler/srcs/op.c \
		  srcs/graphics.c \
		  srcs/windows.c \
#		  srcs/operations/live.c \
		  srcs/operations/ld.c \
		  srcs/operations/st.c \
		  srcs/operations/add.c \
		  srcs/operations/sub.c \
		  srcs/operations/and.c \
		  srcs/operations/or.c \
		  srcs/operations/xor.c \
		  srcs/operations/zjmp.c \
		  srcs/operations/ldi.c \
		  srcs/operations/fork.c \
		  srcs/operations/lld.c \
		  srcs/operations/lldi.c \
		  srcs/operations/lfork.c \
		  srcs/operations/aff.c \

		  
VM_OBJ =  errorh.o \
		  flags.o \
		  init_objs.o \
		  init_players.o \
		  players.o \
		  vm.o \
		  arena.o \
		  print_memory.o \
		  live_checkup.o \
		  loop.o \
		  save_inst.o \
		  op.o \
		  graphics.o \
		  windows.o \
#		  srcs/operations/live.o \
		  srcs/operations/ld.o \
		  srcs/operations/st.o \
		  srcs/operations/add.o \
		  srcs/operations/sub.o \
		  srcs/operations/and.o \
		  srcs/operations/or.o \
		  srcs/operations/xor.o \
		  srcs/operations/zjmp.o \
		  srcs/operations/ldi.o \
		  srcs/operations/fork.o \
		  srcs/operations/lld.o \
		  srcs/operations/lldi.o \
		  srcs/operations/lfork.o \
		  srcs/operations/aff.o \

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(INC) -c $(VM_SRC) 
	@gcc -o $(NAME) $(VM_OBJ) $(LIBFT_PATH)libft.a -lncurses
	@echo "Compiled corewar"

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(VM_OBJ)
	@echo "Cleaned $(VM_OBJ)"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME) *.dSYM
	@echo "Cleaned $(NAME)"

re: fclean all

de: fclean 
	make -C $(LIBFT_PATH)
	gcc -g -o $(NAME) $(FLAGS) $(INC) $(VM_SRC) $(LIBFT_PATH)libft.a
	echo "Compiled corewar"
	
se: fclean 
	make -C $(LIBFT_PATH)
	gcc -g -o $(NAME) -fsanitize=address $(FLAGS) $(INC) $(VM_SRC) $(LIBFT_PATH)libft.a
	echo "Compiled corewar"

test: fclean
	make -C $(LIBFT_PATH)
	gcc -g  -o test $(FLAGS) $(INC) srcs/test.c $(LIBFT_PATH)libft.a
	echo "Compiled test"

FILE = _

.PHONY: all, clean, fclean, re, de
