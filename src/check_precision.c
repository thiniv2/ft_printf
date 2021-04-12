/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:29:05 by thinguye          #+#    #+#             */
/*   Updated: 2021/04/02 16:03:58 by thini-42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_precision(t_info *info)
{
	if (CURR_POS == '.')
	{
		info->precision = 0;
		info->i++;
		info->is_dot = 1;
		while (CURR_POS >= '0' && CURR_POS <= '9')
		{
			info->precision *= 10;
			info->precision += (CURR_POS - 48);
			info->i++;
		}
		if (NEXT_POS == '*')
		{
			info->precision = (int)va_arg(info->args, int);
			info->i++;
		}
	}
	else
		info->precision = -1;
}
