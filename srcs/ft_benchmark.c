/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:59:16 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 15:10:34 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void 	init_bench_count(t_count *bench_count)
{
	bench_count->sa = 0;
	bench_count->sb = 0;
	bench_count->ss = 0;
	bench_count->pa = 0;
	bench_count->rrr = 0;
	bench_count->rrb = 0;
	bench_count->rra = 0;
	bench_count->rr = 0;
	bench_count->rb = 0;
	bench_count->ra = 0;
	bench_count->pb = 0;
	bench_count->total = 0;
}

void	ft_benchmark(t_count *bench_count)
{
	
}
