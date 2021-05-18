/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:16:09 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/18 18:26:04 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	nbr_count(intmax_t nbr, t_info *info)
{
	int	res;

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

intmax_t	print_plus_minus(intmax_t nbr, t_info *info)
{
	if (info->curr_flags[PLUS] && nbr >= 0)
	{
		write(1, "+", 1);
		info->chars_printed++;
		info->minwth--;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		if (info->precision > 0)
			info->minwth--;
		info->chars_printed++;
	}
	return (nbr);
}

void	check_space(t_info *info)
{
	if (info->curr_flags[SPACE] && info->is_negative == 0
		&& !info->curr_flags[PLUS])
	{
		write(1, " ", 1);
		info->minwth--;
		info->chars_printed++;
	}
}

intmax_t	print_front(t_info *info, intmax_t nbr, int len)
{
	if ((!info->curr_flags[MINUS] && info->is_dot == 1)
		|| (info->curr_flags[ZERO] && info->is_dot == 0
			&& !info->curr_flags[MINUS])
		|| (info->minwth && !info->curr_flags[ZERO]
			&& !info->curr_flags[MINUS]))
		print_minwth(info, len);
	nbr = print_plus_minus(nbr, info);
	if ((info->curr_flags[ZERO] && !info->curr_flags[MINUS])
		|| (info->is_dot == 1 && !info->curr_flags[ZERO]
			&& !info->curr_flags[MINUS])
		|| (info->precision >= len && info->curr_flags[MINUS]))
		print_zeros(info, len);
	return (nbr);
}

void	print_d(t_info *info)
{
	intmax_t	nbr;
	int			len;
	char		*str;

	nbr = set_modifier(info);
	if (nbr == 0 && info->precision == 0)
	{
		info->zero = 1;
		info->chars_printed--;
	}
	len = nbr_count(nbr, info);
	if (nbr < 0)
		info->is_negative = 1;
	check_space(info);
	nbr = print_front(info, nbr, len);
	str = ft_itoa_base(nbr, 10);
	if (info->zero == 0)
		ft_putstr(str);
	info->chars_printed += ft_strlen(str);
	if (info->curr_flags[MINUS])
		print_minwth(info, len);
	if (nbr != 0)
		free(str);
}
