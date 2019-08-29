# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:01:51 by jdiaz             #+#    #+#              #
#    Updated: 2019/01/30 19:47:03 by jcruz-y-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

LIBFTPRINTF_PATH = ft_printf

SRC =  ft_memccpy.c \
	   ft_putnbr.c \
   	   ft_strequ.c \
   	   ft_strnequ.c \
	   ft_memchr.c \
   	   ft_putnbr_fd.c \
	   ft_striter.c \
	   ft_strnew.c \
	   ft_atoi.c \
 	   ft_memcmp.c \
   	   ft_putstr.c \
   	   ft_striteri.c \
	   ft_strnstr.c \
	   ft_bzero.c \
   	   ft_memcpy.c \
   	   ft_putstr_fd.c \
	   ft_strjoin.c \
	   ft_strrchr.c \
	   ft_isalnum.c \
	   ft_memdel.c \
   	   ft_strcat.c \
   	   ft_strlcat.c \
	   ft_strsplit.c \
	   ft_isalpha.c \
	   ft_memmove.c \
	   ft_strchr.c \
   	   ft_strlen.c \
	   ft_strstr.c \
	   ft_isascii.c \
	   ft_memset.c \
   	   ft_strclr.c \
	   ft_strmap.c \
   	   ft_strsub.c \
	   ft_isdigit.c \
	   ft_putchar.c \
	   ft_strcmp.c \
   	   ft_strmapi.c \
	   ft_strtrim.c \
	   ft_isprint.c \
   	   ft_putchar_fd.c \
	   ft_strcpy.c \
   	   ft_strncat.c \
	   ft_tolower.c \
	   ft_itoa.c \
 	   ft_putendl.c \
	   ft_strdel.c \
   	   ft_strncmp.c \
	   ft_toupper.c \
	   ft_memalloc.c \
	   ft_putendl_fd.c \
	   ft_strdup.c \
   	   ft_strncpy.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstaddtail.c \
	   itoa_base.c \
	   ft_sort_list.c \
	   ft_num_words.c \
	   skip_lines.c \
	   get_next_line.c \
	   ft_isdigitstr.c \
	   mem_to_int.c \

FT_PRINTF_SRCS = ft_printf/cases.c ft_printf/ft_printf.c ft_printf/ft_pputchar.c \
	   ft_printf/ft_pputnbr.c ft_printf/ft_pputstr.c ft_printf/ft_pstrcmp.c \
       ft_printf/parse_blanks_zeroes.c ft_printf/parse_flags.c ft_printf/parse_rest.c \
	   ft_printf/print_conv_dec_blanks.c ft_printf/print_flags_precision.c ft_printf/xtoa.c \
	   ft_printf/ft_pstrchr.c ft_printf/ft_pstrlen.c ft_printf/parse_arg_length.c \
	   ft_printf/ft_patoi.c

OBJ=$(SRC:.c=.o)

OBJP = cases.o ft_printf.o ft_pputchar.o ft_pputnbr.o ft_pputstr.o ft_pstrcmp.o \
       parse_blanks_zeroes.o parse_flags.o parse_rest.o print_conv_dec_blanks.o \
	   print_flags_precision.o xtoa.o ft_pstrchr.o ft_pstrlen.o parse_arg_length.o \
	   ft_patoi.o

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRC) $(FT_PRINTF_SRCS)
	@ar rc $(NAME) $(OBJ) $(OBJP)
	@ranlib $(NAME)
	@echo "\033[32mBuilt libft library.\033[0m"

clean:
	@/bin/rm -f $(OBJ) $(OBJP)
	@echo "\033[32mCleaned up libft object files.\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32mRemoved library.\033[0m"

re: fclean all

.PHONY: all clean fclean re
