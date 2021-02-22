/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:03:13 by thinguye          #+#    #+#             */
/*   Updated: 2021/02/22 08:19:23 by thinguye         ###   ########.fr       */
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

long double		round_nbr(t_info *info, long double nbr)
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

void			print_f(t_info *info)
{
	/*
	printf("flags: %s\n", info->curr_flags);
	printf("modifs: %s\n", info->curr_modifiers);
	printf("arg: %c\n", info->curr_arg);
	*/
	long double nbr;
	char		*str;
	int			count;

	count = 0;
	nbr = get_modifier(info);
	nbr = round_nbr(info, nbr);
	printf("modif: %Lf\n", nbr);
	str = ft_intmax_itoa((long double)nbr);
	write(1, str, ft_strlen(str));
}
