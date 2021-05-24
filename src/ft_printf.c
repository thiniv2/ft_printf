/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:47:12 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/24 15:48:59 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	init(t_info *info)
{
	info->chars_printed = 0;
	info->i = 0;
	info->zero = 0;
	info->arguments = "cspdiouxXf%";
	info->flag_arr = "#0-+ ";
	info->modifiers = "lhL";
}

int	ft_printf(const char *format, ...)
{
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (format)
	{
		va_start(info->args, format);
		info->format = (char *)format;
		init(info);
		read_format(info);
		va_end(info->args);
		free(info);
	}
	return (info->chars_printed);
}
