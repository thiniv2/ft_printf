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
	
	info->f_prec = info->precision;
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

static void		print_front(t_info *info, char *str)
{
	size_t		len;

	len = 0;
	while (len <= ft_strlen(str) && str[len - 1] != '.')
		len++;
	info->chars_printed += len;
	write(1, str, len);
}

static void		print_decimals(t_info *info, char *str)
{
	size_t		i;
	int		len;

	i = 0;
	if (info->f_prec != -1)
		len = info->f_prec;
	else
		len = 6;
	//printf("len: %d | prec: %d | f_prec: %d\n", len, info->precision, info->f_prec);
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
	if (!info->curr_flags[MINUS])
		print_minwth(info, ft_strlen(str));
	print_front(info, str);
	print_decimals(info, str);
//	write(1, str, ft_strlen(str));
	if (info->curr_flags[MINUS])
		print_minwth(info, ft_strlen(str));
}
