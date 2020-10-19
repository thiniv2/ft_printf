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

void	print_zeros(t_info *info, int len)
{
	int		diff;

	if (info->precision > 0)
	{
		diff = info->precision - len;
		if (info->is_negative)
		{
			//printf("is_negative: %d\n", info->is_negative);
			diff++;
		}
	}
	else
		diff = info->minwth - len;
	//printf("zeroes: %d\n", diff);
	while (diff > 0)
	{
		write(1, "0", 1);
		info->chars_printed++;
		diff--;
	}
}