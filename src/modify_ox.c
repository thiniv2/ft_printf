/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_ox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini <thinguye@student.42.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:01:07 by thini-42          #+#    #+#             */
/*   Updated: 2021/04/12 11:31:48 by thini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_precision(t_info *info, int len, int diff)
{
//	if (info->curr_flags[MINUS])
//		info->minwth += 4;
//	printf ("len: %d | prec: %d | minwth: %d\n", len, info->precision, info->minwth);
	if (info->precision < len)
		diff = info->minwth - len;
	else
		diff = info->minwth - info->precision;
	return (diff);
}

int	modify_ox(t_info *info, int len)
{
	int	diff;

	diff = 0;
	if (!info->precision)
		len--;
	if (info->zero)
		return (info->minwth - len);
	if (info->precision > 0)
		diff = handle_precision(info, len, diff);
	else if (info->curr_flags[ZERO] && !info->curr_flags[MINUS])
		diff = 0;
	else
		diff = info->minwth - len;
	if (info->curr_flags[HASH])
	{
		if (info->curr_arg == 'x' || info->curr_arg == 'X')
			diff--;
		diff--;
	}
	if (info->curr_flags[ZERO] && info->precision == 0)
	{
		diff = info->minwth;
		if (info->curr_flags[HASH])
			diff -= 2;
		diff -= len;
	}
	return (diff);
}
