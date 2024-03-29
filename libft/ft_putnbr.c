/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:49:04 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 17:41:49 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	l;

	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l = l * -1;
	}
	if ((l / 10) > 0)
		ft_putnbr(l / 10);
	ft_putchar(l % 10 + '0');
}
