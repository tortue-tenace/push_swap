/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:59:16 by thattal           #+#    #+#             */
/*   Updated: 2026/05/15 11:37:11 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

void	ft_putfloat2_fd(float f, int fd)
{
	int	integer;
	int	decimal;

	if (f < 0)
	{
		write(fd, "-", 1);
		f = -f;
	}
	integer = (int)f;
	decimal = (int)((f - integer) * 100.0f + 0.5f);
	if (decimal >= 100)
	{
		integer++;
		decimal = 0;
	}
	ft_putnbr_fd(integer, fd);
	write(fd, ".", 1);
	if (decimal < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(decimal, fd);
}

void	init_bench_count(t_count *bench_count)
{
	bench_count->sa = 0;
	bench_count->sb = 0;
	bench_count->ss = 0;
	bench_count->pa = 0;
	bench_count->pb = 0;
	bench_count->ra = 0;
	bench_count->rb = 0;
	bench_count->rr = 0;
	bench_count->rra = 0;
	bench_count->rrb = 0;
	bench_count->rrr = 0;
	bench_count->total = 0;
	bench_count->disorder = 0.0f;
	bench_count->algo = 0;
}
