/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_minwth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:13:22 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/14 17:37:07 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	modify_s(t_info *info, int len)
{
	int	diff;

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
	if (info->f_prec == 0)
		len--;
	if (info->is_negative == 1)
		len++;
	if (info->is_dot == -1)
		return (info->minwth - (len));
	else if (info->is_dot == 1
		&& info->minwth > info->f_prec && info->f_prec > 0)
		return (info->minwth - (len));
	else
		return ((info->minwth - len));
}

void	print_minwth(t_info *info, int len)
{
	int	diff;

	diff = 0;
	if (info->curr_arg == 'd' || info->curr_arg == 'i'
		|| info->curr_arg == 'u')
		diff = modify_d(info, len);
	else if (info->curr_arg == 'o' || info->curr_arg == 'p'
		|| info->curr_arg == 'x' || info->curr_arg == 'X')
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
	while (info->format[info->i] >= '0' && info->format[info->i] <= '9')
	{
		info->minwth *= 10;
		info->minwth += info->format[info->i] - 48;
		info->i++;
	}
	if (info->format[info->i] == '*')
	{
		info->minwth = (int)va_arg(info->args, int);
		info->i++;
	}
}
