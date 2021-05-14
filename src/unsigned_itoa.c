/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:52:10 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/14 18:09:24 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	number_count(uintmax_t value, int base)
{
	int	len;

	len = 0;
	while (value > 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*unsigned_itoa(uintmax_t value, int base)
{
	char	*str;
	char	*new;
	int		len;

	str = "0123456789abcdef";
	if (value == 0)
		return ("0");
	len = number_count(value, base);
	new = (char *)malloc(sizeof(char) * (len + 1));
	new[len] = '\0';
	while (len > 0)
	{
		new[len - 1] = str[value % base];
		value /= base;
		len--;
	}
	return (new);
}

char	*unsigned_itoa_caps(uintmax_t value, int base)
{
	char	*str;
	char	*new;
	int		len;

	str = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	len = number_count(value, base);
	new = (char *)malloc(sizeof(char) * (len + 1));
	new[len] = '\0';
	while (len > 0)
	{
		new[len - 1] = str[value % base];
		value /= base;
		len--;
	}
	return (new);
}
