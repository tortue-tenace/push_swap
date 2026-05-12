/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:16:18 by thattal           #+#    #+#             */
/*   Updated: 2026/04/30 10:59:06 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char type, va_list *ap)
{
	int	i;

	i = 0;
	if (type == 'c')
		i += ft_putchar(va_arg(*ap, int));
	if (type == 's')
		i += ft_putstr(va_arg(*ap, char *));
	if (type == 'd' || type == 'i')
		i += ft_putnbr(va_arg(*ap, int), 10, "0123456789abcdef");
	if (type == 'x')
		i += ft_putnbr(va_arg(*ap, unsigned int), 16, "0123456789abcdef");
	if (type == 'p')
		i += ft_putp(va_arg(*ap, void *));
	if (type == 'X')
		i += ft_putnbr(va_arg(*ap, unsigned int), 16, "0123456789ABCDEF");
	if (type == 'u')
		i += ft_putnbr(va_arg(*ap, unsigned int), 10, "0123456789abcdef");
	if (type == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		i;

	if (!c)
		return (-1);
	va_start(ap, c);
	i = 0;
	while (*c)
	{
		if (*c == '%')
			i += print_format(*(++c), &ap);
		else
			i += write(1, c, 1);
		++c;
	}
	va_end(ap);
	return (i);
}

/*#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	
	printf("%d\n", ft_printf("This is the character %c\n", av[1][0]));
	printf("%d\n", ft_printf("This is the string %s\n", av[1]));
	printf("%d\n", ft_printf("This is the decimal (d) %d\n", atoi(av[2])));
	printf("%d\n", ft_printf("This is the decimal (i) %i\n", atoi(av[2])));
	printf("%d\n", ft_printf("This is the pointer %p\n", av[2]));
	printf("%d\n", ft_printf("This is the unsigned %u\n", abs(atoi(av[2]))));
	printf("%d\n", ft_printf("This is the percentage %%\n"));
	printf("----------------------------------------\n"); 	
	printf("%d\n", printf("This is the character %c\n", av[1][0]));
	printf("%d\n", printf("This is the string %s\n", av[1]));
	printf("%d\n", printf("This is the decimal (d) %d\n", atoi(av[2])));
	printf("%d\n", printf("This is the decimal (i) %i\n", atoi(av[2])));
	printf("%d\n", printf("This is the hexadecimal (in min) %x\n", atoi(av[2])));
	printf("%d\n", printf("This is the pointer %p\n", av[2]));
	printf("%d\n", printf("This is the unsigned %u\n", abs(atoi(av[2]))));
       	printf("%d\n", printf("This is the percentage %%\n"));
	return (0);
}*/
