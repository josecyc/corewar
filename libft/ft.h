/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:55:37 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/31 07:46:03 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define CONV_TYPES "diouxXpfcs%"
# define MOD_TYPES "llhL"
# define FLAGS "# 0-+"

typedef struct	s_ob
{
	int			hashsign;
	int			plus_sign;
	int			space;
	int			minus_sign;
	int			zero;
	int			width;
	int			width_blanks;
	int			left_blanks;
	int			zeroes;
	int			arg_length;
	int			blen;
	int			prec;
	int			prec_bl;
	int			just_dec;
	int			empty;
	char		*mod;
	char		type;
	int			unsig_type;
	int			sig_type;
	int			base;
	int			val_zero;
	va_list		*ap;
	int			neg_num;
	int			counter;
}				t_elem;

int				ft_printf(char *fmt, ...);
void			parse_flags(char **fmt, t_elem *t_node);
void			parse_width(char **fmt, t_elem *t_node);
void			parse_width_blanks(t_elem *t_node);
void			parse_precision(char **fmt, t_elem *t_node, va_list ap);
void			parse_modifier(char **fmt, t_elem *t_node);
void			parse_zeroes(t_elem *t_node);
void			parse_left_just_blanks(t_elem *t_node, int *count);
void			parse_conv_type(char **fmt, t_elem *t_node);
void			parse_arg_length(va_list ap, t_elem *t_node);
void			parse_neg_num(va_list ap, t_elem *t_node);
void			ft_pputstr(char *str, int *count, t_elem *t_node);
void			ft_pputnbr(long long nb, int *count, t_elem *t_node);
void			ft_pputchar(char c, int *count, t_elem *t_node);
void			print_it(char *fmt, t_elem *t_node, va_list ap, int *count);
void			print_width(t_elem *t_node, int *count);
void			print_numsub_plus(t_elem *t_node, int *count);
void			print_space(t_elem *t_node, int *count);
void			print_precision(t_elem *t_node, int *count);
void			print_zeroes(t_elem *t_node, int *count);
void			print_conversion(t_elem *t_node, int *count, va_list ap);
void			print_blanks_just_left(t_elem *t_node, int *count);
void			signed_cases(t_elem *t_node, va_list ap, int *count);
void			float_cases(t_elem *t_node, va_list ap, int *count);
void			unsigned_cases(t_elem *t_node, va_list ap, int *count);
void			pitoa_base(unsigned long long num, t_elem *t_node, int *count);
void			ftoa(double long fnum, long after_pt, int *ct, t_elem *t_node);
int				ft_patoi(const char *str);
long long		ft_round(long double fpart);
void			itoa_blen(unsigned long long num, t_elem *t_node);
int				ft_pstrcmp(const char *str1, const char *str2);
char			*ft_pstrchr(const char *s, int c);
size_t			ft_pstrlen(const char *str);
int				ft_numlen(long long int num);

#endif
