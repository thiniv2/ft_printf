/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:53:29 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 16:21:48 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_u(t_info *info)
{
	uintmax_t		nbr;
	int				len;

	nbr = set_unsigned_modifier(info);
	if (nbr == 0 && info->precision == 0)
		info->zero = 1;
	len = unsigned_nbr_count(nbr, info);
	if (!info->curr_flags[MINUS] && !info->curr_flags[ZERO])
		print_minwth(info, len);
	if ((info->curr_flags[ZERO] && !info->curr_flags[MINUS])
		|| (info->precision > 0))
		print_zeros(info, len);
	if (info->zero == 0)
		ft_putnbr_uintmax(nbr);
	info->chars_printed += len;
	if (info->curr_flags[MINUS])
		print_minwth(info, len);
}
