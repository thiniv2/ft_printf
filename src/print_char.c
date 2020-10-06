/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:42:26 by thinguye          #+#    #+#             */
/*   Updated: 2020/09/17 18:04:58 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_char(t_info *info)
{
	char	c;

	 c = (char)va_arg(info->args, int);
	 if (!(info->curr_flags[MINUS] && info->minwth > 0))
	 	print_minwth(info, 1);
	 write(1, &c, 1);
	 if (info->curr_flags[MINUS])
	 	print_minwth(info, 1);
	info->chars_printed++;
}
