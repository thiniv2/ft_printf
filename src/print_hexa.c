/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:56:24 by thinguye          #+#    #+#             */
/*   Updated: 2020/10/13 10:56:24 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_hexa(t_info *info)
{
	int			len;
	long long	value;
	char		*res;

	value = (long long)va_arg(info->args, long long);
	len = base_nbr_count(value, 16);
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
		print_minwth(info, len);
	if ((info->curr_flags[ZERO] && !info->curr_flags[MINUS]) || info->precision > 0)
		print_zeros(info, len);
	if (info->zero == 0)
		ft_putstr(res);
	info->chars_printed += len;
	if (info->curr_flags[MINUS])
		print_minwth(info, len);
}
