/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:16:09 by thinguye          #+#    #+#             */
/*   Updated: 2020/11/02 07:25:42 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					nbr_count(intmax_t nbr, t_info *info)
{
	int		res;

	res = 0;
	if (info->zero == 1)
		return (0);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		res++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		res++;
	}
	if (info->curr_flags[PLUS])
		res += 0;
	return (res);
}

intmax_t			print_plus_minus(intmax_t nbr, t_info *info)
{
	if (info->curr_flags[PLUS] && nbr >= 0)
	{
		write(1, "+", 1);
		info->chars_printed++;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	return (nbr);
}

void				print_d(t_info *info)
{
	intmax_t		nbr;
	int				len;

	nbr = set_modifier(info);
	if (nbr == 0 && info->precision == 0)
		info->zero = 1;
	len = nbr_count(nbr, info);
	info->is_negative = (nbr < 0) ? 1 : 0;
	if (!info->curr_flags[MINUS])
		print_minwth(info, len);
	nbr = print_plus_minus(nbr, info);
	if ((info->curr_flags[ZERO] && !info->curr_flags[MINUS]
        && info->precision > 0)
    	|| (info->precision > 0))
		print_zeros(info, len);
	if (info->zero == 0)
		ft_putnbr_intmax(nbr);
	info->chars_printed += len;
	if (info->curr_flags[MINUS])
		print_minwth(info, len);
}
