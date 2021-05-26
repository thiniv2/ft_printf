/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 09:56:15 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/24 18:42:26 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(int n, size_t i)
{
	size_t	counter;

	counter = n;
	while (counter != 0)
	{
		counter = counter / 10;
		i++;
	}
	return (i);
}

static void	*ft_loop(char *s, size_t i, size_t n, size_t isnegative)
{
	size_t	res;

	i--;
	while (n != 0)
	{
		res = n % 10;
		s[i--] = res + '0';
		n = n / 10;
		if (isnegative == 1 && i == 0)
			s[i] = '-';
	}
	return (0);
}

static void	ft_setnegative(size_t *isnegative, int *n, size_t *i)
{
	*isnegative = 1;
	*n = - *n;
	*i = *i + 1;
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	isnegative;

	isnegative = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		str = ft_strnew(1);
		str[i] = '0';
		return (str);
	}
	if (n < 0)
		ft_setnegative(&isnegative, &n, &i);
	i = ft_counter(n, i);
	str = ft_strnew(i);
	ft_loop(str, i, n, isnegative);
	return (str);
}
