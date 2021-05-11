/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 09:20:08 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/11 17:29:58 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char delim)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] == delim && s[i + 1] != delim && s[i + 1] != '\0')
			|| (s[i] != delim && i == 0))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_create(size_t *len, size_t *i, char **str, char *s)
{
	str[*i] = ft_strnew(*len);
	str[*i] = ft_strncpy(str[*i], (char *)(s - *len), *len);
	*len = 0;
	*i = *i + 1;
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			len++;
			s++;
		}
		if ((*s != '\0') || (*s == '\0' && *(s - 1) != c))
			str = ft_create(&len, &i, str, (char *)s);
	}
	str[i] = NULL;
	return (str);
}
