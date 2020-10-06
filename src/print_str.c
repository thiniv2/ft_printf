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

	str = (char*)va_arg(info->args, char*);
	len = ft_strlen(str);
	if (!(info->curr_flags[MINUS]) && len < info->minwth)
		print_minwth(info, len);
	if (info->precision < len && info->is_dot == 1)
	{
		write(1, str, info->precision);
		info->chars_printed += info->precision;
	}
	else if (str == NULL)
		ft_putstr("(null)");
	else
	{
		ft_putstr(str);
		info->chars_printed += len;
		if (info->curr_flags[MINUS])
			print_minwth(info, len);
	}
}
