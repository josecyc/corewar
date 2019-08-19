/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:09:01 by jcruz-y-          #+#    #+#             */
/*   Updated: 2018/12/04 21:57:47 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//first pass parsing
//identify name and comment
//separate accordingly (the virtual machine will only consume the program starting
//from the first instruction

//1) #1 op_code byte #2 if encoding flag == 1 encoding byte #3 parameter byte(s)

fd1 = open(argv[1], RD_ONLY)
char	*newfile(char *str)
fd2 = open(argv[1].cor, RDWR) 
get_next_line
void	lexer(char *filename) 		  //Iterate through the whole file and check for lexical errors (op mnemonics, indirect labels correspond, direct and indirect numbers are numbers)
void	locate_labels(char str)       //locate labels in the file
int		get_labels                    //create a table with the labels and its addresses  ex: %:liv == 15, be counting bytes, -1 error
void	create_word_array?            //create a word array with 

int		check_optable(char *str)      	//check op_table
int		get_op_code(char *instruction) 	//iterate through the op_table and get instruction
void	write_op_byt(char **chararr)    //
int		check_par_typ(char *str)      	// check parameter type with op table
int		get_par_type(char *str)        
void	get_encoding_byt(char *str)       //con bitwise operators irlos guardando en un byte 
void	write_encoding_byt(int	rnum_dnum_inum)
void	write_bits(t_asm obj, int fd2)

convert to a decimal number text file
open(argv[1])
