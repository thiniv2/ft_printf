/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:15:34 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/14 18:01:25 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	base_nbr_count(intmax_t value, int base)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		if (base == 10)
			len++;
		value *= -1;
	}
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(intmax_t value, int base)
{
	int			len;
	char		*ret;
	char		*base_str;

	if (value == LONG_MIN || value == LLONG_MIN)
		return (ft_strdup("9223372036854775808"));
	if (value == 0)
		return ("0");
	len = base_nbr_count(value, base);
	base_str = "0123456789abcdef";
	ret = (char *)malloc(sizeof(char) * len + 1);
	ret[len--] = '\0';
	if (value < 0)
	{
		if (base == 10)
			ret[0] = '-';
		value *= -1;
	}
	while (value != 0)
	{
		ret[len] = base_str[value % base];
		value /= base;
		len--;
	}
	return (ret);
}
