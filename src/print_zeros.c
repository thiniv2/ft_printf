/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:23:14 by thinguye          #+#    #+#             */
/*   Updated: 2020/10/01 14:23:14 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_zeros_minwth(t_info *info, int len)
{
	int		diff;

	diff = info->minwth - len;
	while (diff > 0)
	{
		write(1, "0", 1);
		info->chars_printed++;
		diff--;
	}
}

void	print_zeros(t_info *info, int len)
{
	int		diff;

	diff = info->precision - len;
	if (info->is_negative)
		diff++;
	if (info->curr_flags[ZERO])
		print_zeros_minwth(info, len);
	//printf("minwth: %d | diff: %d | len: %d | prec: %d | is_negative: %d\n", info->minwth, diff, len, info->precision, info->is_negative);
	while (diff > 0)
	{
		write(1, "0", 1);
		info->chars_printed++;
		diff--;
	}
}

/*
void		print_zeros(t_info *info, int len)
{
	int		diff;

	diff = info->minwth - len;
	printf("minwth: %d | len: %d | diff: %d | prec: %d\n", info->minwth, len, diff, info->precision);
	if (info->precision > 0)
		diff = info->precision - diff;
	if (info->curr_flags[PLUS])
		diff++;
	while (diff-- > 0)
	{
		write(1, "0", 1);
		info->chars_printed++;
	}
}
*/