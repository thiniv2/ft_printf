/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:22:15 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 17:30:51 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s);
	if ((*s) || (s[1] != '\0'))
	{
		while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
			start = (i++ + 1);
		if (s[start] == '\0')
			return (ft_strnew(0));
		i = ft_strlen(s) - 1;
		while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
			end = (i-- - 1);
		str = ft_strsub(s, start, (end - start) + 1);
		return (str);
	}
	return (ft_strdup(s));
}
