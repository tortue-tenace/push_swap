/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:05:12 by thattal           #+#    #+#             */
/*   Updated: 2026/05/15 16:00:00 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	ft_compute_disorder(t_list **a)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;
	int	size;

	mistakes = 0;
	total_pairs = 0;
	size = ft_lstsize(*a);
	i = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (get_at(*a, i) > get_at(*a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

void	ft_adaptiv_alg(float disorder, t_list **stack_a, t_list **stack_b,
		t_count *bench_count)
{
	if (disorder < 0.2f)
	{
		bench_count->sub_algo = 1;
		ft_bubble_sort(stack_a, bench_count);
	}
	else if (disorder < 0.5f)
	{
		bench_count->sub_algo = 2;
		ft_chunk_sort(stack_a, stack_b, bench_count);
	}
	else
	{
		bench_count->sub_algo = 3;
		ft_radix_sort(stack_a, stack_b, bench_count);
	}
}
