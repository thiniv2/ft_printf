/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:50:07 by thinguye          #+#    #+#             */
/*   Updated: 2021/01/28 19:31:25 by thini-42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double set_double_modifier(t_info *info, long double nbr)
{
	if (ft_strcmp(info->curr_modifiers, "\0") == 0)
		nbr = (double)va_arg(info->args, double);
		
	return ((long double)nbr);
}

intmax_t set_modifier(t_info *info)
{
	intmax_t value;

	if (ft_strcmp(info->curr_modifiers, "h") == 0)
		value = (short)va_arg(info->args, int);
	else if (ft_strcmp(info->curr_modifiers, "hh") == 0)
		value = (signed char)va_arg(info->args, int);
	else if (ft_strcmp(info->curr_modifiers, "l") == 0)
		value = (long)va_arg(info->args, long);
	else if (ft_strcmp(info->curr_modifiers, "ll") == 0)
		value = (long long)va_arg(info->args, long long);
	else if (ft_strcmp(info->curr_modifiers, "L") == 0)
		value = (long double)va_arg(info->args, long double);
	else
		value = (int)va_arg(info->args, int);
	return ((intmax_t)value);
}

uintmax_t set_unsigned_modifier(t_info *info)
{
	intmax_t value;
	if (ft_strcmp(info->curr_modifiers, "h") == 0)
		value = (unsigned short)va_arg(info->args, unsigned int);

	else if (ft_strcmp(info->curr_modifiers, "hh") == 0)
		value = (unsigned char)va_arg(info->args, unsigned int);
	else if (ft_strcmp(info->curr_modifiers, "l") == 0)
		value = (unsigned long)va_arg(info->args, unsigned long);
	else if (ft_strcmp(info->curr_modifiers, "ll") == 0)
		value = (long long)va_arg(info->args, long long);
	else if (ft_strcmp(info->curr_modifiers, "L") == 0)
		value = (unsigned long long)va_arg(info->args, unsigned long long);
	else
		value = (unsigned int)va_arg(info->args, unsigned int);
	return ((uintmax_t)value);
}

void check_modifier(t_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (CURR_POS == 'h' || CURR_POS == 'l' || CURR_POS == 'L')
	{
		while (info->modifiers[i] != '\0')
		{
			while (info->modifiers[i] == CURR_POS)
			{
				if (j < 2)
					info->curr_modifiers[j++] = CURR_POS;
				info->i++;
			}
			i++;
		}
	}
}
