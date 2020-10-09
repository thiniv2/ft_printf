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

int		modify_d(t_info *info, int len)
{
	int		diff;

	diff = 0;
	if (info->precision > 0)
	{
		if (info->precision < len)
			diff = info->minwth - len;
		else
			diff = info->minwth - info->precision;
	}
	else if (info->curr_flags[ZERO])
		diff = 0;
	else
		diff = info->minwth - len;
	if (info->curr_flags[PLUS] && !info->is_negative)
		diff--;
	if (info->is_negative && info->precision > len)
		diff--;
	return(diff);
}

int		modify_s(t_info *info, int len)
{
	int		diff;

	diff = 0;
	if (info->precision == 0)
	{
		diff = info->minwth;
		return (diff);
	}
	if (info->precision > 0 && info->precision < len)
		diff = info->minwth - info->precision;
	else
		diff = info->minwth - len;
	return (diff);
}

void	print_minwth(t_info *info, int len)
{
	int		diff;

	diff = 0;
	if (info->curr_arg == 'd' || info->curr_arg == 'i')
		diff = modify_d(info, len);
	else if (info->curr_arg == 's' || info->curr_arg == 'c')
		diff = modify_s(info, len);
	//printf("minwth: %d | len: %d | diff: %d | prec: %d\n", info->minwth, len, diff, info->precision);
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
