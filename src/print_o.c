/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:07:51 by thinguye          #+#    #+#             */
/*   Updated: 2021/02/08 06:58:05 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		handle_hash_o(t_info *info, uintmax_t value)
{
	if (info->curr_flags[HASH] && value != 0)
	{
		write(1, "0", 1);
		info->chars_printed++;
	}
}

void			print_o(t_info *info)
{
	uintmax_t	value;
	int			len;
	char		*str;

	value = set_unsigned_modifier(info);
	str = ft_uitoa_base(value, 8);
	len = ft_strlen(str);
	if (value == 0 && info->precision == 0)
	{
		info->zero = 1;
		info->chars_printed--;
	}
	if (info->curr_flags[HASH])
		info->precision--;
	if (!info->curr_flags[MINUS])
		print_minwth(info, len);
	handle_hash_o(info, value);
	if ((info->curr_flags[ZERO] && !info->curr_flags[MINUS])
		|| info->precision > 0)
		print_zeros(info, len);
	if (info->zero == 0)
		ft_putstr(str);
	info->chars_printed += len;
	if (info->curr_flags[MINUS])
		print_minwth(info, len);
	if (value > 0)
		free(str);
}
