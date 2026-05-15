/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:18:10 by thattal           #+#    #+#             */
/*   Updated: 2026/05/15 13:40:16 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*ft_prepare(t_list *a, int size)
{
	int	*orig;
	int	*sorted;

	orig = ft_save_orig(a, size);
	sorted = malloc(sizeof(int) * size);
	ft_sorted_orig(orig, sorted, size);
	ft_normalize(a, orig, size);
	free(orig);
	return (sorted);
}

static int	ft_chunk_size(int size)
{
	int	nb_chunks;

	nb_chunks = ft_sqrt_int(size);
	if (nb_chunks < 1)
		nb_chunks = 1;
	return ((size + nb_chunks - 1) / nb_chunks);
}

void	ft_chunk_sort(t_list **a, t_list **b, t_count *bench_count)
{
	int		size;
	int		chunk_size;
	int		chunk;
	int		*sorted;
	t_range	rng;

	size = ft_lstsize(*a);
	sorted = ft_prepare(*a, size);
	chunk_size = ft_chunk_size(size);
	chunk = 0;
	while (*a)
	{
		rng.min = chunk_size * chunk;
		rng.max = chunk_size * (chunk + 1);
		ft_push_chunk(a, b, rng, bench_count);
		chunk++;
	}
	ft_back_to_a(a, b, bench_count);
	ft_restore(*a, sorted);
	free(sorted);
}
