/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_identifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:28:02 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/18 17:18:43 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	read_arg_type(t_info *info)
{
	info->curr_arg = info->format[info->i];
	if (info->format[info->i] == 'c')
		print_c(info);
	else if (info->format[info->i] == 's')
		print_s(info);
	else if ((info->format[info->i] == 'd') || (info->format[info->i] == 'i'))
		print_d(info);
	else if (info->format[info->i] == 'x' || info->format[info->i] == 'X')
		print_x(info);
	else if (info->format[info->i] == 'o')
		print_o(info);
	else if (info->format[info->i] == 'p')
		print_p(info);
	else if (info->format[info->i] == 'u')
		print_u(info);
	else if (info->format[info->i] == '%')
		print_percent(info);
	else if (info->format[info->i] == 'f')
		print_f(info);
	else
	{
		write(1, &info->format[info->i], 1);
		info->chars_printed++;
	}
	info->i++;
}

void	check_flags(t_info *info)
{
	int		i;

	i = 0;
	while (info->flag_arr[i] != '\0')
	{
		while (info->flag_arr[i] == info->format[info->i])
		{
			while (info->format[info->i] == '#' && info->i++)
				info->curr_flags[HASH] = '#';
			while (info->format[info->i] == '0' && info->i++)
				info->curr_flags[ZERO] = '0';
			while (info->format[info->i] == '-' && info->i++)
				info->curr_flags[MINUS] = '-';
			while (info->format[info->i] == '+' && info->i++)
				info->curr_flags[PLUS] = '+';
			while (info->format[info->i] == ' ' && info->i++)
				info->curr_flags[SPACE] = ' ';
			i = 0;
		}
		i++;
	}
}
