/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:45:58 by thini-42          #+#    #+#             */
/*   Updated: 2021/01/26 19:12:20 by thini-42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_float(t_info *info)
{
	long double nbr;

	nbr = set_modifier(info);
	if (nbr < 0)
	{
		info->is_negative = 1;
		nbr *= -1;
	}
}
