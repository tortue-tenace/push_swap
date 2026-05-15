/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurie <lmurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:59:26 by lmurie            #+#    #+#             */
/*   Updated: 2026/05/15 17:00:00 by lmurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n > 0)
	{
		bits++;
		n >>= 1;
	}
	return (bits);
}

static void	ft_radix_pass(t_list **a, t_list **b, int j, t_count *bench_count)
{
	int	i;
	int	size;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->data >> j) & 1)
			ra(a, bench_count);
		else
			pb(a, b, bench_count);
		i++;
	}
	while (*b)
		pa(a, b, bench_count);
}

void	ft_radix_sort(t_list **a, t_list **b, t_count *bench_count)
{
	int	*sorted;
	int	size;
	int	j;
	int	nbdigits;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	sorted = ft_prepare(*a, size);
	if (!sorted)
		return ;
	nbdigits = count_bits(size - 1);
	j = 0;
	while (j < nbdigits)
	{
		ft_radix_pass(a, b, j, bench_count);
		j++;
	}
	ft_restore(*a, sorted);
	free(sorted);
}
