/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_minwth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:13:22 by thinguye          #+#    #+#             */
/*   Updated: 2021/03/19 07:49:55 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		modify_ox(t_info *info, int len)
{
	int		diff;

	diff = 0;
	if (info->zero)
		return (info->minwth - len);
	if (info->precision > 0)
	{
		if (info->precision < len)
			diff = info->minwth - len;
		else
			diff = info->minwth - info->precision;
	}
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

int		modify_d(t_info *info, int len)
{
	int		diff;

	diff = 0;
	if (info->zero != info->curr_flags[MINUS] ||
        (info->curr_flags[ZERO] && info->precision <= 0))
		return (info->minwth - len);
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
	return (diff);
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

int	modify_f(t_info *info, int len)
{
	if (info->minwth > (info->front_len + info->f_prec) && info->f_prec > 0)
		return (info->minwth - (info->front_len + info->f_prec));
	else if (info->minwth > len)
		return (info->minwth - len);
	return (0);
}

void	print_minwth(t_info *info, int len)
{
	int		diff;

	diff = 0;
	if (info->curr_arg == 'd' || info->curr_arg == 'i'
	|| info->curr_arg == 'u')
		diff = modify_d(info, len);
	else if (info->curr_arg == 'o' || info->curr_arg == 'p' ||
			info->curr_arg == 'x' || info->curr_arg == 'X')
		diff = modify_ox(info, len);
	else if (info->curr_arg == 's' || info->curr_arg == 'c')
		diff = modify_s(info, len);
	else if (info->curr_arg == 'f')
		diff = modify_f(info, len);
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
	if (CURR_POS == '*')
	{
		info->minwth = (int)va_arg(info->args, int);
		info->i++;
	}
}
