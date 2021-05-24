/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:42:23 by thini-42          #+#    #+#             */
/*   Updated: 2021/05/24 17:14:34 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_percent(t_info *info)
{
	if (info->curr_flags[MINUS] == '-')
		write(1, "%", 1);
	while (info->minwth > 1 && info->curr_flags[ZERO] != '0')
	{
		write(1, " ", 1);
		info->minwth--;
		info->chars_printed++;
	}
	while (info->minwth > 1 && info->curr_flags[ZERO] == '0'
		&& !info->curr_flags[MINUS])
	{
		write(1, "0", 1);
		info->minwth--;
		info->chars_printed++;
	}
	while (info->minwth > 1 && info->curr_flags[MINUS])
	{
		write(1, " ", 1);
		info->minwth--;
		info->chars_printed++;
	}
	if (info->curr_flags[MINUS] != '-')
		write(1, "%", 1);
	info->chars_printed++;
}
