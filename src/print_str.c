/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:24:29 by thinguye          #+#    #+#             */
/*   Updated: 2020/09/30 19:26:02 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_str(t_info *info)
{
	char		*str;
	int			len;
	char		*print;

	str = (char*)va_arg(info->args, char*);
	if (str == NULL)
		print = "(null)";
	else
		print = ft_strdup(str);
	len = ft_strlen(print);
	if (!(info->curr_flags[MINUS]))
		print_minwth(info, len);
	if (info->precision < len && info->is_dot == 1)
	{
		write(1, print, info->precision);
		if (info->curr_flags[MINUS])
			print_minwth(info, len);
		info->chars_printed += info->precision;
	}
	else
	{
		ft_putstr(print);
		info->chars_printed += len;
		if (info->curr_flags[MINUS])
			print_minwth(info, len);
	}
}
