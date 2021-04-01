/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:23:14 by thinguye          #+#    #+#             */
/*   Updated: 2021/04/01 19:53:09 by thini-42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_zeros(t_info *info, int len)
{
	int		diff;

	if (info->precision == 0)
		return ;
	if (info->precision > 0)
	{
		diff = info->precision - len;
		if (info->is_negative)
			diff++;
	}
	else
		diff = info->minwth - len;
	if ((info->curr_arg == 'x' || info->curr_arg == 'X' || info->curr_arg == 'o') && 
		info->curr_flags[HASH])
	{
		if (info->curr_arg == 'x' || info->curr_arg == 'X')
			info->minwth--;
		info->minwth--;
	}

	if (info->curr_flags[HASH] && info->precision < 0)
		diff -= 2;

	while (diff > 0)
	{
		write(1, "0", 1);
		info->chars_printed++;
		diff--;
	}
}
