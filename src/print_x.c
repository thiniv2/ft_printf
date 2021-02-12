/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:56:24 by thinguye          #+#    #+#             */
/*   Updated: 2021/02/08 06:57:16 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		handle_hash_x(t_info *info, uintmax_t value)
{
	if (info->curr_flags[HASH] && value != 0)
	{
		if (info->curr_arg == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		info->chars_printed += 2;
        info->minwth += 2;
	}
}

void			print_x(t_info *info)
{
	uintmax_t	value;
	char		*res;

	value = set_unsigned_modifier(info);
	if (info->curr_arg == 'x')
		res = ft_itoa_base(value, 16);
	else
		res = ft_itoa_base_caps(value, 16);
	if (value == 0 && info->precision == 0)
	{
		info->zero = 1;
		info->chars_printed--;
	}
	if (!info->curr_flags[MINUS])
		print_minwth(info, ubase_nbr_count(value, 16));
	handle_hash_x(info, value);
	if ((info->curr_flags[ZERO] && !info->curr_flags[MINUS])
		|| info->precision > 0)
		print_zeros(info, ubase_nbr_count(value, 16));
	if (info->zero == 0)
		ft_putstr(res);
	info->chars_printed += ubase_nbr_count(value, 16);
	if (info->curr_flags[MINUS])
		print_minwth(info, ubase_nbr_count(value, 16));
	if (value > 0)
		free(res);
}
