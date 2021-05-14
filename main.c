/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:48:09 by thinguye          #+#    #+#             */
/*   Updated: 2021/05/14 18:08:29 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i;
	int min_int;
	int max_int;
	int		ret1;
	int		ret2;
	uintmax_t uintmax;
	long long ll;
	int a;
	int b;
	char s1[90];
	char *str;

	ll = 9223372036854775807;
	uintmax = 18446744073709551615u;
	i = 142;
	min_int = -2147483648;
	max_int = 2147483647;

// 	sprintf(s1, "TESTING FLOATS\n");
// 	write(1, s1, strlen(s1));
// 	float f = 12.45;

// // TEST 1
// 	ret1 =  sprintf(s1, "a1: |%f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b1: |%f|", f);
// 	ft_printf(" %d\n", ret2);

// //  TEST 2
// 	ret1 =  sprintf(s1, "a2: |%15f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b2: |%15f|", f);
// 	ft_printf(" %d\n", ret2);
	
// //  TEST 3
// 	ret1 =  sprintf(s1, "a3: |%-10f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b3: |%-10f|", f);
// 	ft_printf(" %d\n", ret2);
	
// //  TEST 4
// 	ret1 =  sprintf(s1, "a4: |%.1f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b4: |%.1f|", f);
// 	ft_printf(" %d\n", ret2);

// //  TEST 5
// 	ret1 =  sprintf(s1, "a5: |%9.4f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b5: |%9.4f|", f);
// 	ft_printf(" %d\n", ret2);

// //  TEST 6
// 	ret1 =  sprintf(s1, "a6: |%5.f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b6: |%5.f|", f);
// 	ft_printf(" %d\n", ret2);

// //  TEST 7
// 	ret1 =  sprintf(s1, "a7: |%-4.2f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b7: |%-4.2f|", f);
// 	ft_printf(" %d\n", ret2);

// //  TEST 8
// 	ret1 =  sprintf(s1, "a8: |%013f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b8: |%013f|", f);
// 	ft_printf(" %d\n", ret2);

// //  TEST 9
// 	ret1 =  sprintf(s1, "a9: |%010.1f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b9: |%010.1f|", f);
// 	ft_printf(" %d\n", ret2);
	
// //  TEST 10
// 	ret1 =  sprintf(s1, "a10: |%.0f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b10: |%.0f|", f);
// 	ft_printf(" %d\n", ret2);
	
// //  TEST 11
// 	ret1 =  sprintf(s1, "a11: |%05.f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b11: |%05.f|", f);
// 	ft_printf(" %d\n", ret2);

// //  TEST 12
// 	ret1 =  sprintf(s1, "a12: |%-15.4f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b12: |%-15.4f|", f);
// 	ft_printf(" %d\n", ret2);
	
// //  TEST 13
// 	ret1 =  sprintf(s1, "a13: |%-05.f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b13: |%-05.f|", f);
// 	ft_printf(" %d\n", ret2);
	
// //  TEST 14
// 	ret1 =  sprintf(s1, "a14: |%014.6f|", f);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b14: |%014.6f|", f);
// 	ft_printf(" %d\n", ret2);

// 	//	TESTING PERCENT
// 	sprintf(s1, "\nTESTING PERCENT\n");
// 	write(1, s1, strlen(s1));

// //  TEST 1
// 	ret1 =  sprintf(s1, "a1: |%|");
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b1: |%|");
// 	ft_printf(" %d\n", ret2);


// //  TEST 2
// 	ret1 =  sprintf(s1, "a2: |%%|");
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b2: |%%|");
// 	ft_printf(" %d\n", ret2);


// //  TEST 3
// 	ret1 =  sprintf(s1, "a3: |%5%|");
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b3: |%5%|");
// 	ft_printf(" %d\n", ret2);


// //  TEST 4
// 	ret1 =  sprintf(s1, "a4: |%-%|");
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b4: |%-%|");
// 	ft_printf(" %d\n", ret2);

// //  TEST 5
// 	ret1 =  sprintf(s1, "a5: |%06%|");
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b5: |%06%|");
// 	ft_printf(" %d\n", ret2);

// //  TEST 6
// 	ret1 =  sprintf(s1, "a6: |%-5%|");
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b6: |%-5%|");
// 	ft_printf(" %d\n", ret2);

// //	TESTING STR

// 	sprintf(s1, "\nTESTING STR\n");
// 	write(1, s1, strlen(s1));

// 	str = "hello world";
// //	TEST 1
// 	sprintf(s1, "a1: |%s|\n", str);
// 	write(1, s1, strlen(s1));
// 	ft_printf("b1: |%s|\n", str);


// //	TEST 2
// 	sprintf(s1, "a2: |%05.3s|\n", str);
// 	write(1, s1, strlen(s1));
// 	ft_printf("b2: |%05.3s|\n", str);

// //	TEST 3
// 	sprintf(s1, "a3: |%016.6s|\n", str);
// 	write(1, s1, strlen(s1));
// 	ft_printf("b3: |%016.6s|\n", str);

// //	TEST 4
// 	sprintf(s1, "a4: |%-16.10s|\n", str);
// 	write(1, s1, strlen(s1));
// 	ft_printf("b4: |%-16.10s|\n", str);

// //	TEST 5
// 	sprintf(s1, "a5: |%-016.s|\n", str);
// 	write(1, s1, strlen(s1));
// 	ft_printf("b5: |%-016.s|\n", str);

// //	TEST 6
// 	sprintf(s1, "a6: |%-13s|\n", str);
// 	write(1, s1, strlen(s1));
// 	ft_printf("b6: |%-13s|\n", str);

// //	TEST 7
// 	sprintf(s1, "a7: |%-0.13s|\n", str);
// 	write(1, s1, strlen(s1));
// 	ft_printf("b7: |%-0.13s|\n", str);


// //  TESTING D

// 	i = 0;
// 	sprintf(s1, "\nTESTING D\n");
// 	write(1, s1, strlen(s1));

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

// //  TEST 4
// 	ret1 =  sprintf(s1, "a4: |%+05.6d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b4: |%+05.6d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 5
// 	ret1 =  sprintf(s1, "a5: |%-5d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b5: |%-5d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 6
// 	ret1 =  sprintf(s1, "a6: |%-05.d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b6: |%-05.d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 7
// 	ret1 =  sprintf(s1, "a7: |%07.d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b7: |%07.d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 8
// 	ret1 =  sprintf(s1, "a8: |%07.1d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b8: |%07.1d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 9
// 	ret1 =  sprintf(s1, "a9: |%0.5d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b9: |%0.5d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 10
// 	ret1 =  sprintf(s1, "a10: |%0+5d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b10: |%0+5d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 11
// 	ret1 =  sprintf(s1, "a11: |%5d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b11: |%5d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 12
// 	ret1 =  sprintf(s1, "a12: |%-10.5d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b12: |%-10.5d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 13
// 	ret1 =  sprintf(s1, "a13: |%-+10.5d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b13: |%-+10.5d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 14
// 	ret1 =  sprintf(s1, "a14: |%03.5d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b14: |%03.5d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 15
// 	ret1 =  sprintf(s1, "a15: |% 03d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b15: |% 03d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 16
// 	ret1 =  sprintf(s1, "a16: |% +d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b16: |% +d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 17
// 	ret1 =  sprintf(s1, "a17: |%lld|", LLONG_MIN);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b17: |%lld|", LLONG_MIN);
// 	ft_printf(" %d\n", ret2);

// //  TEST 18
// 	ret1 =  sprintf(s1, "a18: |%lld|", LLONG_MAX);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b18: |%lld|", LLONG_MAX);
// 	ft_printf(" %d\n", ret2);

// //  TEST 19
// 	ret1 =  sprintf(s1, "a19: |%-+06.2d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b19: |%-+06.2d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 20
// 	ret1 =  sprintf(s1, "a20: |%-+06.0d|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b20: |%-+06.0d|", i);
// 	ft_printf(" %d\n", ret2);

// //  TEST 21
// 	ret1 =  sprintf(s1, "a21: |%+10.5d|", 4242);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b21: |%+10.5d|", 4242);
// 	ft_printf(" %d\n", ret2);

// //  TEST 22
// 	ret1 =  sprintf(s1, "a22: |%04.2d|", -1);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b21: |%04.2d|", -1);
// 	ft_printf(" %d\n", ret2);

// //  TEST 23
// 	ret1 =  sprintf(s1, "a23: |%.d|", 0);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b23: |%.d|", 0);
// 	ft_printf(" %d\n", ret2);

// 	// TESTING xX

// 	sprintf(s1, "\nTESTING xX\n");
// 	write(1, s1, strlen(s1));
// 	i = 0;

// //	TEST 1
// 	ret1 = sprintf(s1, "a1: |%5.4x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b1: |%5.4x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 2
// 	ret1 = sprintf(s1, "a2: |%#-14.8x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b2: |%#-14.8x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 3
// 	ret1 = sprintf(s1, "a3: |%#-.4x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b3: |%#-.4x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 4
// 	ret1 = sprintf(s1, "a4: |%0-5x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b4: |%0-5x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 5
// 	ret1 = sprintf(s1, "a5: |%04.0x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b5: |%04.0x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 6
// 	ret1 = sprintf(s1, "a6: |%0-8.x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b6: |%0-8.x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 7
// 	ret1 = sprintf(s1, "a7: |%#-5.6x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b7: |%#-5.6x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 8
// 	ret1 = sprintf(s1, "a8: |%#07.x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b8: |%#07.x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 9
// 	ret1 = sprintf(s1, "a9: |%#-08x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b9: |%#-08x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 10
// 	ret1 = sprintf(s1, "a10: |%#08x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b10: |%#08x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 11
// 	ret1 = sprintf(s1, "a11: |%#6x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b11: |%#6x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 12
// 	ret1 = sprintf(s1, "a12: |%#.0x| %#.0x|", i, i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b12: |%#.0x| %#.0x|", i, i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 13
// 	ret1 = sprintf(s1, "a13: |%5.x %5.0x|", i, i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b13: |%5.x %5.0x|", i, i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 14
// 	ret1 = sprintf(s1, "a14: |%#x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b14: |%#x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 15
// 	ret1 = sprintf(s1, "a15: |%#.x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b15: |%#.x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 16
// 	ret1 = sprintf(s1, "a16: |%#x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b16: |%#x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 17
// 	ret1 = sprintf(s1, "a17: |%#.0x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b17: |%#.0x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 18
// 	ret1 = sprintf(s1, "a18: |%#.x %#.0x|", 0, i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b18: |%#.x %#.0x|", 0, i);
// 	ft_printf(" %d\n", ret2);
	
// //	TEST 19
// 	ret1 = sprintf(s1, "a19: |%#-08x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b19: |%#-08x|", i);
// 	ft_printf(" %d\n", ret2);
	
// //	TEST 20
// 	ret1 = sprintf(s1, "a20: |%-#08x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b20: |%-#08x|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 21
// 	ret1 = sprintf(s1, "a21: |%#-8.x|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b21: |%#-8.x|", i);
// 	ft_printf(" %d\n", ret2);


// //	TESTING OCTAL WITHOUT ZERO
// 	sprintf(s1, "TESTING OCTAL\n");
// 	write(1, s1, strlen(s1));
// 	i = 42;

// //	TEST 1
// 	ret1 = sprintf(s1, "a1: |%o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b1: |%o|", i);
// 	ft_printf(" %d\n", ret2);
	
// //	TEST 2
// 	ret1 = sprintf(s1, "a2: |%05o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b2: |%05o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 3
// 	ret1 = sprintf(s1, "a3: |%-2.6o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b3: |%-2.6o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 4
// 	ret1 = sprintf(s1, "a4: |%#6o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b4: |%#6o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 5
// 	ret1 = sprintf(s1, "a5: |%#-4.o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b5: |%#-4.o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 6
// 	ret1 = sprintf(s1, "a6: |%#5.4o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b6: |%#5.4o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 7
// 	ret1 = sprintf(s1, "a7: |%#5.o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b7: |%#5.o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 8
// 	ret1 = sprintf(s1, "a8: |%#-8o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b8: |%#-8o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 9
// 	ret1 = sprintf(s1, "a9: |%#8o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b9: |%#8o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 10
// 	ret1 = sprintf(s1, "a10: |%#-8.0o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b10: |%#-8.0o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 11
// 	ret1 = sprintf(s1, "a11: |%#-4o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b11: |%#-4o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 12
// 	ret1 = sprintf(s1, "a12: |%#.o| |%.0o|", i, i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b12: |%#.o| |%.0o|", i, i);
// 	ft_printf(" %d\n", ret2);

// // TESTING OCTAL
// 	sprintf(s1, "TESTING OCTAL WITH ZEROS\n");
// 	write(1, s1, strlen(s1));
// 	i = 0;

// //	TEST 1
// 	ret1 = sprintf(s1, "a1: |%o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b1: |%o|", i);
// 	ft_printf(" %d\n", ret2);
	
// //	TEST 2
// 	ret1 = sprintf(s1, "a2: |%05o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b2: |%05o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 3
// 	ret1 = sprintf(s1, "a3: |%-2.6o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b3: |%-2.6o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 4
// 	ret1 = sprintf(s1, "a4: |%#6o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b4: |%#6o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 5
// 	ret1 = sprintf(s1, "a5: |%#-4.o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b5: |%#-4.o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 6
// 	ret1 = sprintf(s1, "a6: |%#5.4o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b6: |%#5.4o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 7
// 	ret1 = sprintf(s1, "a7: |%#5.o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b7: |%#5.o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 8
// 	ret1 = sprintf(s1, "a8: |%#-8o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b8: |%#-8o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 9
// 	ret1 = sprintf(s1, "a9: |%#8o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b9: |%#8o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 10
// 	ret1 = sprintf(s1, "a10: |%#-8.0o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b10: |%#-8.0o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 11
// 	ret1 = sprintf(s1, "a11: |%#-4o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b11: |%#-4o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 12
// 	ret1 = sprintf(s1, "a12: |%#.o| |%.0o|", i, i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b12: |%#.o| |%.0o|", i, i);
// 	ft_printf(" %d\n", ret2);
	
// //	TEST 13
// 	ret1 = sprintf(s1, "a13: |%#5.o| |%5.0o|", i, i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b13: |%#5.o| |%5.0o|", i, i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 14
// 	ret1 = sprintf(s1, "a14: |%#.0o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b14: |%#.0o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 15
// 	ret1 = sprintf(s1, "a15: |%#07.o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b15: |%#07.o|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 16
// 	ret1 = sprintf(s1, "a16: |%#-8.o|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b16: |%#-8.o|", i);
// 	ft_printf(" %d\n", ret2);


// // TESTING UNSIGNED
// 	i = 32;
// 	sprintf(s1, "TESTING UNSIGNED\n");
// 	write(1, s1, strlen(s1));

// //	TEST 1
// 	ret1 = sprintf(s1, "a1: |%u|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b1: |%u|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 2
// 	ret1 = sprintf(s1, "a2: |%#05u|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b2: |%#05u|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 3
// 	ret1 = sprintf(s1, "a3: |%#-5u|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b3: |%#-5u|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 4
// 	ret1 = sprintf(s1, "a4: |%#+03u|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b4: |%#+03u|", i);
// 	ft_printf(" %d\n", ret2);

// //	TEST 5
// 	ret1 = sprintf(s1, "a4: |%#3.5u|", i);
// 	write(1, s1, strlen(s1));
// 	ft_printf(" %d\n", ret1);
// 	ret2 = ft_printf("b4: |%#3.5u|", i);
// 	ft_printf(" %d\n", ret2);


	ret1 = sprintf(s1, "x min: |%llx|", LLONG_MIN);
	write(1, s1, strlen(s1));
	ft_printf(" %d\n", ret1);
	ret2 = ft_printf("x min: |%llx|", LLONG_MIN);
	ft_printf(" %d\n", ret2);
	
	ret1 = sprintf(s1, "X max: |%llX|", LLONG_MAX);
	write(1, s1, strlen(s1));
	ft_printf(" %d\n", ret1);
	ret2 = ft_printf("X max: |%llX|", LLONG_MAX);
	ft_printf(" %d\n", ret2);
	
	ret1 = sprintf(s1, "x umax: |%llx|", ULLONG_MAX);
	write(1, s1, strlen(s1));
	ft_printf(" %d\n", ret1);
	ret2 = ft_printf("x umax: |%llx|", ULLONG_MAX);
	ft_printf(" %d\n", ret2);

	ret1 = sprintf(s1, "o min: |%llo|", LLONG_MIN);
	write(1, s1, strlen(s1));
	ft_printf(" %d\n", ret1);
	ret2 = ft_printf("o min: |%llo|", LLONG_MIN);
	ft_printf(" %d\n", ret2);
	
	ret1 = sprintf(s1, "o max: |%llo|", LLONG_MAX);
	write(1, s1, strlen(s1));
	ft_printf(" %d\n", ret1);
	ret2 = ft_printf("o max: |%llo|", LLONG_MAX);
	ft_printf(" %d\n", ret2);

	ret1 = sprintf(s1, "o umax: |%llo|", ULLONG_MAX);
	write(1, s1, strlen(s1));
	ft_printf(" %d\n", ret1);
	ret2 = ft_printf("o umax: |%llo|", ULLONG_MAX);
	ft_printf(" %d\n", ret2);

	ret1 = sprintf(s1, "|%llo, %llo|", 0llu, ULLONG_MAX);
	write(1, s1, strlen(s1));
	ft_printf(" %d\n", ret1);
	ret2 = ft_printf("|%llo, %llo|", 0llu, ULLONG_MAX);
	ft_printf(" %d\n", ret2);

	return (0);
}
