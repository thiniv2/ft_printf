/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:47:12 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/10 19:38:13 by thinguye         ###   ########.fr       */
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

/*
** doesn't return chars_printed if (info) is freed on linux
*/

int	ft_printf(const char *format, ...)
{
	t_info		*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (-1);
	if (format)
	{
		va_start(info->args, format);
		info->format = (char *)format;
		init(info);
		read_format(info);
		va_end(info->args);
	//	free(info);
	}
	return (info->chars_printed);
}
