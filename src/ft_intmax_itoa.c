/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:28:41 by thinguye          #+#    #+#             */
/*   Updated: 2021/02/22 08:19:45 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			count_nbr(intmax_t nbr)
{
	long res;
	
	res = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr >= 10)
	{
		nbr /= 10;
		res++;
	}
	return (res + 1);
}

char		*ft_intmax_itoa(intmax_t nbr)
{
	intmax_t	i;
	char		*dst;
	printf("JD: %jd\n", nbr);
	i = count_nbr(nbr);
	if (nbr < 0)
	{
		if (!(dst = ft_strnew(i + 1)))
			return (NULL);
		dst[0] = '-';
		nbr = -nbr;
	}
	else if (!(dst = ft_strnew(i--)))
		return (NULL);
	if (nbr == 0)
		dst[0] = '0';
	while (nbr > 0)
	{
		dst[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	return (dst);
}