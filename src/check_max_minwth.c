/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minwth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:13:22 by thinguye          #+#    #+#             */
/*   Updated: 2020/09/30 19:26:27 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_minwth(t_info *info, int len)
{
	int		diff;

	if (info->precision > 0)
		diff = info->minwth - info->precision;
	else
		diff = info->minwth - len;
	if (info->is_negative)
	{
		printf("is negative: ");
		if (info->curr_flags[PLUS])
		{
			diff++;
			printf("plus\n");
		}
		else
		{
			//diff--;
			printf("minus\n");
		}
	}
	printf("minwth: %d | len: %d | diff: %d | prec: %d\n", info->minwth, len, diff, info->precision);
	while (diff-- > 0)
	{
		write(1, " ", 1);
		info->chars_printed++;
	}
}

void	check_minwth(t_info *info)
{
	while (CURR_POS >= '0' && CURR_POS <= '9')
	{
		info->minwth *= 10;
		info->minwth += CURR_POS - 48;
		info->i++;
	}
}
