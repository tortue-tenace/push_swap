/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:00:00 by thattal           #+#    #+#             */
/*   Updated: 2026/05/15 17:00:00 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	print_strategy(int algo)
{
	if (algo == 0)
		ft_putstr_fd("Adaptive", 2);
	else if (algo == 1)
		ft_putstr_fd("Simple / O(n\xc2\xb2)", 2);
	else if (algo == 2)
		ft_putstr_fd("Medium / O(n\xe2\x88\x9an)", 2);
	else if (algo == 3)
		ft_putstr_fd("Complex / O(n log n)", 2);
}

static void	print_ops_sa(t_count *c)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(c->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(c->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(c->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(c->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(c->pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_ops_ra(t_count *c)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(c->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(c->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(c->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(c->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(c->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(c->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_benchmark(t_count *c)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putfloat2_fd(c->disorder, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	print_strategy(c->algo);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(c->total, 2);
	ft_putstr_fd("\n", 2);
	print_ops_sa(c);
	print_ops_ra(c);
}
