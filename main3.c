/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:08:34 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/18 17:12:22 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	int ret1;
	int ret2;
	char *s1[90];
	int i;
	char *str;

	i = 0;
	str = NULL;

//  TEST 7
	ret1 =  sprintf(s1, "a7: |%-0.13s|", str);
	write(1, s1, strlen(s1));
	ft_printf(" %d\n", ret1);
	ret2 = ft_printf("b7: |%-0.13s|", str);
	ft_printf(" %d\n", ret2);

// //	TEST 8
// 	ret1 = sprintf(s1, "a8: |%s %s %s|", "Hello", "World", "!");
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b8: |%s %s %s|", "Hello", "World", "!");
// 	ft_printf(" %d\n", ret2);

// //  TEST 1
// 	ret1 =  sprintf(s1, "a1: |%0-8d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b1: |%0-8d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 2
// 	ret1 =  sprintf(s1, "a2: |%.4d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b2: |%0.4d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 3
// 	ret1 =  sprintf(s1, "a3: |%05.d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b3: |%05.d|", i);
// 	ft_printf(" %d\n", ret2);

	while (1);
	return(0);
}