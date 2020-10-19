/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:44:30 by thinguye          #+#    #+#             */
/*   Updated: 2020/10/16 12:02:25 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"


int		main(void)
{
	int		i;
	int		a;
	int		b;
	char	*s1;
	char	*str;

	i = 0;
	a = printf("a1: |%-.4o|\n", i);
 b = ft_printf("b1: |%-.4o|\n", i);
	printf("a: %d | b: %d\n", a, b);

/*
	i = 42;
	sprintf(s1, "a1: |%5.4d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b1: |%5.4d|\n", i);

	write(1, "\n", 1);

	i = -1;
	sprintf(s1, "a2: |%+4.3d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b2: |%+4.3d|\n", i);

	write(1, "\n", 1);

	i = 42;
	sprintf(s1, "a3: |%06.4d|\n", i);
	write(1, s1, strlen(s1));
	ft_printf("b3: |%06.4d|\n", i);

	write(1, "\n", 1);

	i = 42;
	str = "hehe";
	sprintf(s1, "a4: |%-2.s|\n", str);
	write(1, s1, strlen(s1));
	ft_printf("b4: |%-2.s|\n", str);

	write(1, "\n", 1);

	sprintf(s1, "a5: |%6.3d|\n", i);
	write(1, s1, strlen(s1));


	ft_printf("b5: |%6.3d|\n", i);
	ft_printf("ft_printf: |%6s|\n", "Hello");
	printf("printf:    |%6s|\n", "Hello");
	printf("%04d\n", 123);
	printf("|%-5d|\n", 10);
	printf("|%+5d|\n", 10);
	printf("%05d\n", 10);
	printf("|%10s|\n", "Hello");
	printf("|%-10s|\n", "Hello");
	b = ft_printf("ft_printf: BA%cAB%0%\n", 'K');
	printf("\n");
	a = printf("printf:    BA%cAB%0%\n", 'K');
	printf("printed chars:\n");
	printf("oma: %d printf: %d\n", b, a);	
	ft_printf("ft_printf: ");
	b = ft_printf("%s\n", str);
	printf("printf: ");
	a = printf("%s\n", str);
	printf("printed chars:\n");
	printf("oma: %d printf: %d\n", b, a);	

	ft_printf("ft_printf: %%\n");
	ft_printf("ft_printf: zero: %0%\n");
	ft_printf("\nft_printf: BA%cAB\n", 'K');
	ft_printf("ft_printf: %s\n", str);
	ft_printf("ft_printf: %s\n", "Bonjour Les Gens");
	ft_printf("ft_printf: bonjour %s %s les gens\n", NULL, NULL);

	printf("\n");
	printf("printf: %%\n");
	printf("printf: zero: %0%\n");
	printf("printf: BA%cAB\n", 'K');
	printf("printf: %s\n", str);
	printf("printf: %s\n", "Bonjour Les Gens");
	printf("printf: bonjour %s %s les gens\n", NULL, NULL);
	printf("printf: %s %s %s %s\n", NULL, NULL, NULL, NULL);
	printf("printf: %s\n", str);
	printf("printf: %s\n", "Bonjour Les Gens");
	printf("printf: %s\n", NULL);
	printf("testi 1 %10.3s\n", "moro vaan moro moro");
	printf("|%*d|\n", 5, 10);
	printf("%#x\n", 12); //prints: 0xc
	printf("%04d\n", 42); //prints: 0042
	printf("%+d\n", 52); //prints: +52
	printf("|%-5d|\n", 64); //prints: |64   |
	printf("testi 1 %2#.3s\n", "moro vaan moro moro");
	printf("%3#.5u\n", 42);
	printf("%.2L#3i\n", 1234567890123456789);
*/
	return (0);
}
