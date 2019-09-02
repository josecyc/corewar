# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 19:22:08 by jdiaz             #+#    #+#              #
#    Updated: 2019/09/02 12:06:12 by jcruz-y-         ###   ########.fr        #
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
		  srcs/instructions/inst_live.c \
		  srcs/instructions/inst_ld.c \
		  srcs/instructions/inst_st.c \
		  srcs/instructions/inst_add.c \
		  srcs/instructions/inst_sub.c \
		  srcs/instructions/inst_and.c \
		  srcs/instructions/inst_or.c \
		  srcs/instructions/inst_xor.c \
		  srcs/instructions/inst_zjmp.c \
		  srcs/instructions/inst_ldi.c \
		  srcs/instructions/inst_fork.c \
		  srcs/instructions/inst_lld.c \
		  srcs/instructions/inst_lldi.c \
		  srcs/instructions/inst_lfork.c \
		  srcs/instructions/inst_aff.c \

		  
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
		  inst_live.o \
		  inst_ld.o \
		  inst_st.o \
		  inst_add.o \
		  inst_sub.o \
		  inst_and.o \
		  inst_or.o \
		  inst_xor.o \
		  inst_zjmp.o \
		  inst_ldi.o \
		  inst_fork.o \
		  inst_lld.o \
		  inst_lldi.o \
		  inst_lfork.o \
		  inst_aff.o \

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	#@gcc $(FLAGS) $(INC) -c $(VM_SRC) 
	@gcc $(INC) -c $(VM_SRC) 
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
