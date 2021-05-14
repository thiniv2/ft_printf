/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_convs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:52:58 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/14 18:03:26 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_uintmax(uintmax_t nbr)
{
	if ((nbr / 10) > 0)
		ft_putnbr_uintmax(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int	unsigned_nbr_count(uintmax_t nbr, t_info *info)
{
	int		res;

	res = 0;
	if (info->zero == 1)
		return (0);
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		res++;
	}
	if (info->curr_flags[PLUS])
		res += 0;
	return (res);
}

int	ubase_nbr_count(uintmax_t value, int base)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}
