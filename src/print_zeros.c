/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:23:14 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/14 17:37:18 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_zeros_f(t_info *info, int len)
{
	int		diff;

	diff = 0;
	len += 0;
	if (info->curr_flags[ZERO] && !info->curr_flags[MINUS])
	{
		if (info->is_dot == 1)
		{
			diff = (info->front_len + info->f_prec);
			if (info->f_prec != 0)
				diff++;
		}
		else
			diff = info->front_len + 7;
		info->minwth -= diff;
		if (info->is_negative == 0)
			info->minwth++;
		while (info->minwth > 0)
		{
			write(1, "0", 1);
			info->chars_printed++;
			info->minwth--;
		}
	}
}

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
	while (diff > 0)
	{
		write(1, "0", 1);
		info->chars_printed++;
		diff--;
	}
}
