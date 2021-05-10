/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_ox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini <thinguye@student.42.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:10:16 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/04 08:35:52 by thini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_precision(t_info *info, int len, int diff)
{
	if (info->precision < len)
		diff = info->minwth - len;
	else
		diff = info->minwth - info->precision;
	return (diff);
}

int	modify_ox(t_info *info, int len)
{
	int	diff;
	int	plus;

	diff = 0;
	plus = 0;
	if (info->zero)
	{
		if ((info->curr_arg == 'x' || info->curr_arg == 'X'))
			plus = 1;
		if (!info->curr_flags[HASH])
			return ((info->minwth - len) + 1);
		else
			return ((info->minwth - len) + plus);
	}
	if (info->precision > 0)
		diff = handle_precision(info, len, diff);
	else if (info->curr_flags[ZERO] && !info->curr_flags[MINUS])
		diff = 0;
	else
		diff = info->minwth - len;
	
	if (info->curr_flags[HASH] && info->is_dot == 0)
	{
		if (info->curr_arg == 'x' || info->curr_arg == 'X')
			diff -= 2;
		else if (info->curr_arg == 'o')
			diff--;
	}
	if (info->curr_flags[ZERO] && info->precision == 0)
	{
		diff = info->minwth;
		diff -= len;
	}
	return (diff);
}
