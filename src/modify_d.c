/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:34:15 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 16:38:27 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_prec(t_info *info, int diff, int len)
{
	if (info->precision < len)
	{
		diff = info->minwth - len;
		if (info->curr_flags[PLUS] || info->curr_flags[MINUS])
			diff++;
	}
	else
		diff = info->minwth - info->precision;
	if (info->is_negative || (info->curr_flags[PLUS]
			&& !info->curr_flags[MINUS]))
		diff--;
	return (diff);
}

int	modify_d(t_info *info, int len)
{
	int	diff;

	diff = 0;
	if (info->precision > len && info->curr_flags[MINUS])
		return (info->minwth - info->precision);
	if ((info->curr_flags[ZERO] && info->precision <= 0))
		return (info->minwth - len);
	if (info->precision > 0)
		diff = handle_prec(info, diff, len);
	else if (info->curr_flags[ZERO])
		diff = 0;
	else
		diff = info->minwth - len;
	return (diff);
}