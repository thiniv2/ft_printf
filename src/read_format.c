/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:36:36 by thinguye          #+#    #+#             */
/*   Updated: 2020/09/30 17:01:26 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_value(t_info *info)
{
	info->maxwth = 0;
	info->minwth = 0;
	info->precision = 0;
	info->is_dot = 0;
	info->is_negative = 0;
	info->curr_flags[HASH] = '\0';
	info->curr_flags[ZERO] = '\0';
	info->curr_flags[MINUS] = '\0';
	info->curr_flags[PLUS] = '\0';
	info->curr_flags[SPACE] = '\0';
	info->curr_flags[5] = '\0';
}

void	call_readers(t_info *info)
{
	info->i++;
	set_value(info);
	check_flags(info);
	check_minwth(info);
	check_precision(info);
	//lenght modifier
	read_arg_type(info);
}

void	read_format(t_info *info)
{
	while (CURR_POS)
	{
		if (CURR_POS == '%' && NEXT_POS == '%')
		{
			write(1, &CURR_POS, 1);
			info->i += 2;
			info->chars_printed++;
		}
		else if (CURR_POS == '%')
			call_readers(info);
		else
		{
			write(1, &CURR_POS, 1);
			info->chars_printed++;
			info->i++;
		}
	}
}
