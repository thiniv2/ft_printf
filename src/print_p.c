/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:05:51 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/24 17:14:06 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	front_print(t_info *info, int len)
{
	if (!info->curr_flags[MINUS])
		print_minwth(info, len);
	if (info->curr_flags[ZERO] && !info->curr_flags[MINUS])
		print_zeros(info, len);
	ft_putstr("0x");
	if (info->precision > len)
		print_zeros(info, len);
}

void	print_p(t_info *info)
{
	int			len;
	uintmax_t	value;
	char		*res;

	value = (long long)va_arg(info->args, long long);
	res = ft_itoa_base(value, 16);
	len = ft_strlen(res);
	info->minwth -= 2;
	if (value == 0 && info->precision == 0)
	{
		info->zero = 1;
		info->chars_printed--;
	}
	front_print(info, len);
	if (info->zero == 0)
		ft_putstr(res);
	info->chars_printed += len + 2;
	if (info->curr_flags[MINUS])
		print_minwth(info, len);
	if (value > 0)
		free(res);
}
