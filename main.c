/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:44:30 by thinguye          #+#    #+#             */
/*   Updated: 2021/03/03 17:59:08 by thini-42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <assert.h>

int		main(void)
{
	int				i;
	int				min_int;
	int				max_int;
	uintmax_t		uintmax;
	long long		ll;
	int				a;
	int				b;
	char			*s1[90];
	char			*str;

	ll = 9223372036854775807;
	uintmax = 18446744073709551615u;
	i = 142;
	min_int = -2147483648;
	max_int = 2147483647;

	sprintf(s1, "TESTING FLOATS\n");
	write(1, s1, strlen(s1));
	
	float f = 5.35;
	sprintf(s1, "a1: |%f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b1: |%f|\n", f);

	f = 6.123456789;
	sprintf(s1, "a2: |%f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b2: |%f|\n", f);
	
	f = 1235.12312312389;
	sprintf(s1, "a3: |%f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b3: |%f|\n", f);
	
/*
	f = 5.123456789;
	sprintf(s1, "a3: |%5.2f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b3: |%5.2f|\n", f);
	
	f = 8.23748;
	sprintf(s1, "a4: |%15f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b4: |%15f|\n", f);
	
	f = -9.127386123;
	sprintf(s1, "a4: |%15f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b4: |%15f|\n", f);
*/
/*	
	f = 4;
	sprintf(s1, "a1: |%f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b1: |%f|\n", f);
*/
/*
	//TESTING FLOATS
	sprintf(s1, "TESTING FLOATS\n");
	write(1, s1, strlen(s1));

	float f = 5.35;

	sprintf(s1, "a1: |%f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b1: |%f|\n", f);

	sprintf(s1, "a2: |%.3f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b2: |%.3f|\n", f);

	sprintf(s1, "a3: |%10f|\n", f);
	write(1, s1, strlen(s1));
	ft_printf("b3: |%10f|\n", f);


	//	TESTING PERCENT
	sprintf(s1, "\nTESTING PERCENT\n");
	write(1, s1, strlen(s1));

	sprintf(s1, "a1: |%%|\n");
	write(1, s1, strlen(s1));
	ft_printf("b1: |%%|\n");

	sprintf(s1, "a2: |%6%|\n");
	write(1, s1, strlen(s1));
	ft_printf("b2: |%6%|\n");

	sprintf(s1, "a3: |%-%|\n");
	write(1, s1, strlen(s1));
	ft_printf("b3: |%-%|\n");

	sprintf(s1, "a4: |%06%|\n");
	write(1, s1, strlen(s1));
	ft_printf("b4: |%06%|\n");
*/
/*

//	TESTING STR
	sprintf(s1, "\nTESTING STR\n");
	write(1, s1, strlen(s1));

	str = "hello world";
//	TEST 1
	sprintf(s1, "a1: |%s|\n", str);
	write(1, s1, strlen(s1));
	ft_printf("b1: |%s|\n", str);


//	TEST 2
	sprintf(s1, "a2: |%05.3s|\n", str);
	write(1, s1, strlen(s1));
	ft_printf("b2: |%05.3s|\n", str);

//	TEST 3
	sprintf(s1, "a3: |%016.6s|\n", str);
	write(1, s1, strlen(s1));
	ft_printf("b3: |%016.6s|\n", str);

//	TEST 4
	sprintf(s1, "a4: |%-16.10s|\n", str);
	write(1, s1, strlen(s1));
	ft_printf("b4: |%-16.10s|\n", str);

//	TEST 5
	sprintf(s1, "a5: |%-016.s|\n", str);
	write(1, s1, strlen(s1));
	ft_printf("b5: |%-016.s|\n", str);

//	TEST 6
	sprintf(s1, "a6: |%-13s|\n", str);
	write(1, s1, strlen(s1));
	ft_printf("b6: |%-13s|\n", str);


//  TESTING D
	sprintf(s1, "\nTESTING D\n");
	write(1, s1, strlen(s1));
//  TEST 1
	sprintf(s1, "a1: |%0-8d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b1: |%0-8d|\n", i);

//  TEST 2
    sprintf(s1, "a2: |%.4d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b2: |%.4d|\n", i);

//  TEST 3
    sprintf(s1, "a3: |%05.d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b3: |%05.d|\n", i);

//  TEST 4
    sprintf(s1, "a4: |%#05.6d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b4: |%#05.6d|\n", i);

//  TEST 5
    sprintf(s1, "a5: |%-5d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b5: |%-5d|\n", i);

//  TEST 6
    sprintf(s1, "a6: |%-05.d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b6: |%-05.d|\n", i);

//  TEST 7
    sprintf(s1, "a7: |%07.d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b7: |%07.d|\n", i);

//  TEST 8
    sprintf(s1, "a8: |%07.1d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b8: |%07.1d|\n", i);

//  TEST 9
    sprintf(s1, "a9: |%0.5d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b9: |%0.5d|\n", i);


// TESTING xX

	sprintf(s1, "\nTESTING xX\n");
	write(1, s1, strlen(s1));
	i = 42;
//	TEST 1
	sprintf(s1, "a1: |%5.4x|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b1: |%5.4x|\n", i);

//	TEST 2
	sprintf(s1, "a2: |%#-10.6x|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b2: |%#-10.6x|\n", i);

//	TEST 3
	sprintf(s1, "a3: |%#-.4x|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b3: |%#-.4x|\n", i);

//	TEST 4
	sprintf(s1, "a4: |%0-5x|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b4: |%0-5x|\n", i);

//	TEST 5
	sprintf(s1, "a5: |%04.0x|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b5: |%04.0x|\n", i);

//	TEST 6
	sprintf(s1, "a6: |%05x|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b6: |%05x|\n", i);

//	TEST 7
	sprintf(s1, "a7: |%#-5.6x|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b7: |%#-5.6x|\n", i);

//	TEST 8
	sprintf(s1, "a8: |%#07.x|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b8: |%#07.x|\n", i);

	// TESTING OCTAL
	i = 42;

	sprintf(s1, "TESTING OCTAL\n");
	write(1, s1, strlen(s1));


//	TEST 1
	sprintf(s1, "a1: |%o|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b1: |%o|\n", i);

//	TEST 2
	sprintf(s1, "a2: |%05o|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b2: |%05o|\n", i);

//	TEST 3
	sprintf(s1, "a3: |%-2.6o|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b3: |%-2.6o|\n", i);

//	TEST 4
	sprintf(s1, "a4: |%#6o|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b4: |%#6o|\n", i);

//	TEST 5
	sprintf(s1, "a5: |%#-4.o|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b5: |%#-4.o|\n", i);

//	TEST 6
	sprintf(s1, "a6: |%#5.4o|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b6: |%#5.4o|\n", i);

//	TEST 7
	sprintf(s1, "a6: |%#5.o|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b6: |%#5.o|\n", i);

	sprintf(s1, "A percent: |%%|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("B percent: |%%|\n", i);

	sprintf(s1, "A percent 2: |%5%|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("B percent 2: |%5%|\n", i);
*/
	return (0);
}
