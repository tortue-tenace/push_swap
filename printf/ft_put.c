/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:46:07 by thattal           #+#    #+#             */
/*   Updated: 2026/04/29 12:20:42 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(long n, int base, char *symbols)
{
	int	i;

	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-n, base, symbols) + 1);
	}
	else if (n < base)
		return (ft_putchar(symbols[n]));
	else
	{
		i = ft_putnbr(n / base, base, symbols);
		return (i + ft_putnbr(n % base, base, symbols));
	}
}

int	ft_putp(void *x)
{
	int	i;

	i = 0;
	if (x == NULL)
		return (ft_putstr("(nil)"));
	i += write (1, "0x", 2);
	i += ft_putnbr((long)x, 16, "0123456789abcdef");
	return (i);
}
