/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:03:13 by thinguye          #+#    #+#             */
/*   Updated: 2021/02/08 07:04:19 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		get_nbr_len(t_info *info, intmax_t nbr)
{
	if (ft_strcmp(info->curr_modifiers, "L") == 0)
		nbr = (va_arg(info->args, long double));
	else
		nbr = va_arg(info->args, double);
	return ((long double)nbr);
}

long double		round_nbr(t_info *info, long double nbr)
{
	long double		i;
	int				count;

	if (info->is_dot != '.')
		info->precision = 6;
	i = 0.500;
	count = info->precision;
	if (info->is_dot == 1 && info->precision == 0)
		count = 0;
	while (count > 0 && count--)
		i/= 10;
	if (nbr < 0)
	{
		i *= -1;
		info->is_negative = 1;
	}
	nbr *= i;
	return (nbr);
}

void			print_f(t_info *info)
{
	long double nbr;
	char		*str;
	int			count;

	count = 0;
	nbr = get_nbr_len(info, 0);
	nbr = round_nbr(info, nbr);
	if (info->precision == 0 && info->is_dot)
	{
		str = ft_intmax_itoa((intmax_t)nbr);
		printf("%s\n", str);
	}
}
