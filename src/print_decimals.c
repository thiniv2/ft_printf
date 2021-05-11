/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:06:34 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 17:08:41 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double	get_decimal(t_info *info, long double nbr)
{
	long double		factor;
	int				count;

	info->f_prec = info->precision;
	if (info->is_dot != 1)
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

void	print_decimals(t_info *info, char *str)
{
	size_t	i;
	int		len;

	i = 0;
	if (info->f_prec != -1)
		len = info->f_prec;
	else
		len = 6;
	while (str[i] != '.')
		i++;
	i++;
	while (len > 0)
	{
		write(1, &str[i], 1);
		info->chars_printed++;
		i++;
		len--;
	}
}
