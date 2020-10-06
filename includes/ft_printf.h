/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:45:01 by thinguye          #+#    #+#             */
/*   Updated: 2020/09/30 17:00:55 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# include <stdio.h> // DELETE

# define CURR_POS info->format[info->i]
# define NEXT_POS info->format[info->i + 1]
# define PREV_POS info->format[info->i - 1]

typedef struct		s_info
{
	int				chars_printed;
	int				i;
	int				maxwth;
	int				minwth;
	int				precision;
	int				is_dot;
	int				is_negative;
	char			*format;
	char			*arguments;
	char			*modifiers;
	char			*flag_arr;
	char			curr_flags[6];
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

int					ft_printf(const char *format, ...);
void				print_char(t_info *info);
void				read_format(t_info *info);
void				check_flags(t_info *info);
void				read_arg_type(t_info *info);
void				print_str(t_info *info);
void				check_minwth(t_info *info);
void				print_minwth(t_info *info, int len);
void				check_precision(t_info *info);
void				print_d(t_info *info);
void				print_zeros(t_info *info, int len);
#endif
