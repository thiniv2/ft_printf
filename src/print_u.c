/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:53:29 by thinguye          #+#    #+#             */
/*   Updated: 2020/10/25 15:53:31 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_invis_plus(t_info *info)
{
	write(1, " ", 1);
	info->chars_printed++;
}

void		print_u(t_info *info)
{
	uintmax_t		nbr;
	int				len;

	nbr = set_unsigned_modifier(info);
	if (nbr == 0 && info->precision == 0)
		info->zero = 1;
	len = unsigned_nbr_count(nbr, info);
	if (!info->curr_flags[MINUS])
		print_minwth(info, len);
	if (info->curr_flags[PLUS])
		print_invis_plus(info);
	if ((info->curr_flags[ZERO] && !info->curr_flags[MINUS])
	|| (info->precision > 0))
		print_zeros(info, len);
	if (info->zero == 0)
		ft_putnbr_uintmax(nbr);
	info->chars_printed += len;
	if (info->curr_flags[MINUS])
		print_minwth(info, len);
}
