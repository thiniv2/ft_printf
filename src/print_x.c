/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini <thinguye@student.42.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:56:24 by thinguye          #+#    #+#             */
/*   Updated: 2021/04/12 11:14:34 by thini            ###   ########.fr       */
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

char			*check_caps(t_info *info, uintmax_t value)
{
	if (info->curr_arg == 'x')
		return (ft_itoa_base(value, 16));
	else
		return (ft_itoa_base_caps(value, 16));
}

void			print_x(t_info *info)
{
	uintmax_t	value;
	char		*res;
	int			len;

	value = set_unsigned_modifier(info);
	len = ubase_nbr_count(value, 16);
	res = check_caps(info, value);
	if (value == 0 && info->precision == 0)
	{
		info->zero = 1;
		info->chars_printed--;
	}
	if (info->curr_flags[HASH] && info->precision < 0)
		info->minwth -= 2;
	if (!info->curr_flags[MINUS])
	{
		if (info->curr_flags[HASH] && info->precision != -1 && value == 0)
			len--;
		print_minwth(info, len);
	}
	handle_hash_x(info, value);
	if ((info->curr_flags[ZERO] && !info->curr_flags[MINUS])
		|| info->precision > 0)
		print_zeros(info, len);
	if (info->zero == 0)
		ft_putstr(res);
	info->chars_printed += len;
	if (info->curr_flags[MINUS])
	{
		if (info->curr_flags[HASH] && info->precision != -1 && value == 0)
			len--;
		print_minwth(info, len);
	}
	if (value > 0)
		free(res);
}
