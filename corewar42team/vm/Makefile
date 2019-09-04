# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 19:22:08 by jdiaz             #+#    #+#              #
#    Updated: 2019/09/03 21:46:02 by viclucas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

### PATH ###
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = ../libft/

FLAGS = -Wall -Werror -Wextra -g

INC = -I ./includes/ -I ./$(LIBFT_PATH)

VM_SRC	= srcs/graph_bonus.c \
		  srcs/errorh.c \
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
		  srcs/inst_utils.c \
		  srcs/instructions/inst_live.c \
		  srcs/instructions/inst_ld.c \
		  srcs/instructions/inst_ldi.c \
		  srcs/instructions/inst_st.c \
		  srcs/instructions/inst_sti.c \
		  srcs/instructions/inst_add.c \
		  srcs/instructions/inst_sub.c \
		  srcs/instructions/inst_and.c \
		  srcs/instructions/inst_or.c \
		  srcs/instructions/inst_xor.c \
		  srcs/instructions/inst_zjmp.c \
		  srcs/instructions/inst_fork.c \
		  srcs/instructions/inst_lld.c \
		  srcs/instructions/inst_lldi.c \
		  srcs/instructions/inst_lfork.c \
		  srcs/instructions/inst_aff.c \

		  
VM_OBJ =  $(VM_SRC:.c=.o)

all: $(NAME)

$(NAME): $(VM_OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(INC) $(VM_OBJ) -o $(NAME) -L $(LIBFT_PATH) -lft -lncurses
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
	
se: fclean $(VM_OBJ) 
	make -C $(LIBFT_PATH)
	@gcc -fsanitize=address $(FLAGS) $(VM_OBJ) -o $(NAME) -L $(LIBFT_PATH) -lft -lncurses
	#gcc -g -o $(NAME) -fsanitize=address $(FLAGS) $(INC) $(VM_OBJ) $(LIBFT_PATH)libft.a
	echo "Compiled corewar"

test: fclean
	make -C $(LIBFT_PATH)
	gcc -g  -o test $(FLAGS) $(INC) srcs/test.c $(LIBFT_PATH)libft.a
	echo "Compiled test"

FILE = _

.PHONY: all, clean, fclean, re, de
