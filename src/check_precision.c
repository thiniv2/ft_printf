/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:29:05 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 14:28:47 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_precision(t_info *info)
{
	if (info->format[info->i] == '.')
	{
		info->precision = 0;
		info->i++;
		info->is_dot = 1;
		while (info->format[info->i] >= '0' && info->format[info->i] <= '9')
		{
			info->precision *= 10;
			info->precision += (info->format[info->i] - 48);
			info->i++;
		}
		if (info->format[info->i + 1] == '*')
		{
			info->precision = (int)va_arg(info->args, int);
			info->i++;
		}
	}
	else
		info->precision = -1;
}
