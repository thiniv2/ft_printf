/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:45:01 by thinguye          #+#    #+#             */
/*   Updated: 2021/03/03 17:58:12 by thini-42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "../libft/libft.h"

# include <stdio.h> // DELETE

# define CURR_POS info->format[info->i]
# define NEXT_POS info->format[info->i + 1]
# define PREV_POS info->format[info->i - 1]
# define LLONG_MIN  (-__LONG_LONG_MAX__-1LL)
# define LONG_MIN  (-__LONG_MAX__ -1L)

typedef struct		s_info
{
	int				chars_printed;
	int				zero;
	int				i;
	int				minwth;
	int				precision;
	int				f_prec;
	int				is_dot;
	int				is_negative;
	char			*format;
	char			*arguments;
	char			*modifiers;
	char			*flag_arr;
	char			curr_flags[6];
	char			curr_arg;
	char			curr_modifiers[3];
	va_list			args;
}					t_info;

typedef enum		e_flags
{
	HASH = 0,
	ZERO = 1,
	MINUS = 2,
	PLUS = 3,
	SPACE = 4,
}					t_flags;

void				print_c(t_info *info);
void				print_p(t_info *info);
void				print_d(t_info *info);
void				print_x(t_info *info);
void				print_o(t_info *info);
void				print_u(t_info *info);
void				print_f(t_info *info);
void				print_s(t_info *info);
void				print_zeros(t_info *info, int len);
void				print_percent(t_info *info);

int					ft_printf(const char *format, ...);
int					base_nbr_count(intmax_t value, int base);
char				*ft_itoa_base(intmax_t value, int base);
char				*ft_itoa_base_caps(intmax_t value, int base);
void				print_char(t_info *info);
void				read_format(t_info *info);
void				check_flags(t_info *info);
void				read_arg_type(t_info *info);
void				print_str(t_info *info);
void				check_minwth(t_info *info);
void				print_minwth(t_info *info, int len);
void				check_precision(t_info *info);
void				ft_putnbr_intmax(intmax_t nbr);
void				check_modifier(t_info *info);
int					nbr_count(intmax_t nbr, t_info *info);
intmax_t			print_plus_minus(intmax_t nbr, t_info *info);
intmax_t			set_modifier(t_info *info);
uintmax_t			set_unsigned_modifier(t_info *info);
int					unsigned_nbr_count(uintmax_t nbr, t_info *info);
void				ft_putnbr_uintmax(uintmax_t nbr);
char				*ft_uitoa_base_caps(uintmax_t value, int base);
char				*ft_uitoa_base(uintmax_t value, int base);
int					ubase_nbr_count(uintmax_t value, int base);
char				*ft_ftoa(long double src, int prec);
#endif
