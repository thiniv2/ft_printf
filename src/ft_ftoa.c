/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:23:30 by thini-42          #+#    #+#             */
/*   Updated: 2021/04/02 16:06:15 by thini-42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		count_nbr(intmax_t nbr)
{
	long	res;

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

char	*ft_intmax_itoa(intmax_t nbr)
{
	intmax_t	i;
	char		*dst;

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

char	*first_part(intmax_t src2, long double src)
{
	char	*dst;

	dst = ft_intmax_itoa(src2);
	if (src < 0 && ft_strcmp("0", dst) == 0)
		dst = ft_strjoin("-", dst);
	return (dst);
}

char	*ft_ftoa(long double src, int prec)
{
	int			i;
	char		*dst1;
	char		*dst2;
	char		*res;
	intmax_t	src2;

	src2 = (intmax_t)src;
	dst1 = first_part(src2, src);
	if (src < 0)
		src *= -1;
	if (src2 < 0)
		src *= -1;
	i = 0;
	dst2 = ft_strnew(prec + 2);
	dst2[i++] = '.';
	while (prec-- > 0)
	{
		src = (src - (long double)src2) * 10;
		src2 = (intmax_t)src;
		dst2[i++] = src2 + '0';
	}
	res = ft_strjoin(dst1, dst2);
	free(dst1);
	free(dst2);
	return (res);
}
