/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:03:13 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/18 16:42:47 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double	get_modifier(t_info *info)
{
	long double	nbr;

	if (ft_strcmp(info->curr_modifiers, "L") == 0)
		nbr = (va_arg(info->args, long double));
	else
		nbr = va_arg(info->args, double);
	return ((long double)nbr);
}

static void	print_front(t_info *info, char *str)
{
	int		len;

	len = 0;
	while (len <= (int)ft_strlen(str) && str[len] != '.')
		len++;
	info->chars_printed += len;
	write(1, str, len);
}

static void	check_front_len(t_info *info, char *str)
{
	int		len;

	len = 0;
	while (len <= (int)ft_strlen(str) && str[len - 1] != '.')
		len++;
	info->front_len = len;
}

long double	handle_negative(t_info *info, long double nbr)
{
	if (nbr < 0)
	{
		nbr *= -1;
		info->is_negative = 1;
		info->chars_printed++;
	}
	return (nbr);
}

void	print_f(t_info *info)
{
	long double	nbr;
	char		*str;

	nbr = get_modifier(info);
	nbr = get_decimal(info, nbr);
	nbr = handle_negative(info, nbr);
	str = ft_ftoa(nbr, info->precision);
	check_front_len(info, str);
	if (!info->curr_flags[MINUS] && !info->curr_flags[ZERO])
		print_minwth(info, ft_strlen(str));
	if (info->is_negative == 1)
		write(1, "-", 1);
	print_zeros_f(info, ft_strlen(str));
	print_front(info, str);
	if (info->f_prec != 0)
	{
		write(1, ".", 1);
		info->chars_printed++;
	}
	print_decimals(info, str);
	if (info->curr_flags[MINUS])
		print_minwth(info, ft_strlen(str));
	if (str)
		free(str);
}
