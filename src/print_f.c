/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:03:13 by thinguye          #+#    #+#             */
/*   Updated: 2021/03/03 17:55:30 by thini-42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double		get_modifier(t_info *info)
{
	long double		nbr;
	if (ft_strcmp(info->curr_modifiers, "L") == 0)
		nbr = (va_arg(info->args, long double));
	else
		nbr = va_arg(info->args, double);
	return ((long double)nbr);
}

long double		get_decimal(t_info *info, long double nbr)
{
	long double		factor;
	int				count;
	
	if (info->is_dot != '.')
		info->precision = 6;
	factor = 0.500;
	count = info->precision;
	if (info->is_dot == 1 && info->precision == 0)
		count = 0;
	while (count > 0 && count--)
		factor /= 10;
	if (nbr < 0)
	{
		factor *= -1;
		info->is_negative = 1;
	}
	nbr += factor;
	return (nbr);
}

/*
** TODO: fix if given value is negative,
** fix precision and width flags
*/

void			print_f(t_info *info)
{
	long double nbr;
	char		*str;

	nbr = get_modifier(info);
	nbr = get_decimal(info, nbr);
	str = ft_ftoa(nbr, info->precision);
	write(1, str, ft_strlen(str));
}
