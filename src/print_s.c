/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:24:29 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 17:13:47 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_print(t_info *info, char *str, int len)
{
	write(1, str, len);
	info->chars_printed += len;
}

void	print_s(t_info *info)
{
	char		*str;
	int			len;
	char		*print;

	str = (char *)va_arg(info->args, char *);
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
		handle_print(info, print, len);
		if (info->curr_flags[MINUS])
			print_minwth(info, len);
	}
}
