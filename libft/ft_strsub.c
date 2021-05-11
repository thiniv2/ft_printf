/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:52:31 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 17:30:27 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = NULL;
	if (s)
	{
		mem = ft_strnew(len);
		while (i < len)
		{
			mem[i] = s[start];
			i++;
			start++;
		}
	}
	return (mem);
}
