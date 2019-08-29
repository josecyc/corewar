# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 16:10:03 by jcruz-y-          #+#    #+#              #
#    Updated: 2019/01/09 20:25:16 by jcruz-y-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRCS = cases.c ft_printf.c ft_pputchar.c ft_pputnbr.c ft_pputstr.c ft_pstrcmp.c \
       parse_blanks_zeroes.c parse_flags.c parse_rest.c print_conv_dec_blanks.c \
	   print_flags_precision.c xtoa.c ft_pstrchr.c ft_pstrlen.c parse_arg_length.c \
	   ft_patoi.c

SRCSO = cases.o ft_printf.o ft_pputchar.o ft_pputnbr.o ft_pputstr.o ft_pstrcmp.o \
       parse_blanks_zeroes.o parse_flags.o parse_rest.o print_conv_dec_blanks.o \
	   print_flags_precision.o xtoa.o ft_pstrchr.o ft_pstrlen.o parse_arg_length.o \
	   ft_patoi.o

HEADER = -I=ft.h

$(NAME): 
	gcc $(FLAGS) -c $(SRCS) $(HEADER)
	ar rcs $(NAME) $(SRCSO)
	ranlib $(NAME)

test: fclean
	/bin/rm -f test
	gcc -g -o test $(FLAGS) $(HEADER) ../test.c $(SRCS)
#	./test

tclean:
	/bin/rm -f test
	/bin/rm -rf test.dSYM

all: $(NAME)

clean: 
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
