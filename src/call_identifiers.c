/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_identifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:28:02 by thinguye          #+#    #+#             */
/*   Updated: 2020/07/21 15:09:15 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		read_arg_type(t_info *info)
{
	info->curr_arg = CURR_POS;
	if (CURR_POS == 'c')
		print_char(info);
	else if (CURR_POS == 's')
		print_str(info);
	else if ((CURR_POS == 'd') || (CURR_POS == 'i'))
		print_d(info);
	else if (CURR_POS == 'x' || CURR_POS == 'X')
		print_hexa(info);
	else if (CURR_POS == 'o')
		print_octal(info);
	else if (CURR_POS == 'p')
		print_p(info);
	else if (CURR_POS == 'u')
		print_u(info);
	else if (CURR_POS == '%')
		print_percent(info);
	info->i++;
}

void		check_flags(t_info *info)
{
	int		i;

	i = 0;
	while (info->flag_arr[i] != '\0')
	{
		while (info->flag_arr[i] == CURR_POS)
		{
			while (CURR_POS == '#' && info->i++)
				info->curr_flags[HASH] = '#';
			while (CURR_POS == '0' && info->i++)
				info->curr_flags[ZERO] = '0';
			while (CURR_POS == '-' && info->i++)
				info->curr_flags[MINUS] = '-';
			while (CURR_POS == '+' && info->i++)
				info->curr_flags[PLUS] = '+';
			while (CURR_POS == ' ' && info->i++)
				info->curr_flags[SPACE] = ' ';
			i = 0;
		}
		i++;
	}
}
