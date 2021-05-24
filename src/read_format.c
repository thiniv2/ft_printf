/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:36:36 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/24 17:14:56 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_tmp_values(t_info *info)
{
	info->minwth = 0;
	info->precision = -1;
	info->f_prec = -1;
	info->is_dot = -1;
	info->is_negative = 0;
	info->front_len = 0;
	info->zero = 0;
	info->curr_flags[HASH] = '\0';
	info->curr_flags[ZERO] = '\0';
	info->curr_flags[MINUS] = '\0';
	info->curr_flags[PLUS] = '\0';
	info->curr_flags[SPACE] = '\0';
	info->curr_flags[5] = '\0';
	info->curr_modifiers[0] = '\0';
	info->curr_modifiers[1] = '\0';
	info->curr_modifiers[2] = '\0';
}

void	call_readers(t_info *info)
{
	info->i++;
	if (info->format[info->i] == '\0')
		return ;
	set_tmp_values(info);
	check_flags(info);
	check_minwth(info);
	check_precision(info);
	check_modifier(info);
	read_arg_type(info);
}

void	read_format(t_info *info)
{
	while (info->format[info->i])
	{
		if (info->format[info->i] == '%' && info->format[info->i + 1] == '%')
		{
			write(1, &info->format[info->i], 1);
			info->i += 2;
			info->chars_printed++;
		}
		else if (info->format[info->i] == '%')
			call_readers(info);
		else
		{
			write(1, &info->format[info->i], 1);
			info->chars_printed++;
			info->i++;
		}
	}
}
