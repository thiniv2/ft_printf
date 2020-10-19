/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:07:51 by thinguye          #+#    #+#             */
/*   Updated: 2020/10/13 15:07:51 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_octal(t_info *info)
{
	long long	value;
	int		len;
	char		*str;

	value = (long long)va_arg(info->args, long long);
	str = ft_itoa_base(value, 8);
	len = ft_strlen(str);
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
		ft_putstr(str);
	info->chars_printed += len;
	if (info->curr_flags[MINUS])
		print_minwth(info, len);
}
