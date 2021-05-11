/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:35:35 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 17:27:23 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (s)
	{
		str = ft_strnew(ft_strlen(s));
		while (s[i])
		{
			str[i] = f(i, (s[i]));
			i++;
		}
	}
	return (str);
}
