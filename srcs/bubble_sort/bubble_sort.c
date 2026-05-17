/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurie <lmurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:35:56 by thattal           #+#    #+#             */
/*   Updated: 2026/05/17 11:00:36 by lmurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_index(t_list *a)
{
	int	min_val;
	int	min_idx;
	int	idx;

	min_val = a->data;
	min_idx = 0;
	idx = 0;
	while (a)
	{
		if (a->data < min_val)
		{
			min_val = a->data;
			min_idx = idx;
		}
		a = a->next;
		idx++;
	}
	return (min_idx);
}

static void	rotate_to_top(t_list **a, int idx, t_count *bench_count)
{
	int	size;
	int	back;

	size = ft_lstsize(*a);
	if (idx <= size / 2)
	{
		while (idx-- > 0)
			ra(a, bench_count);
	}
	else
	{
		back = size - idx;
		while (back-- > 0)
			rra(a, bench_count);
	}
}

void	ft_bubble_sort(t_list **a, t_count *bench_count)
{
	t_list	*b;
	int		size;
	int		idx;

	b = NULL;
	size = ft_lstsize(*a);
	while (size > 0)
	{
		idx = find_min_index(*a);
		rotate_to_top(a, idx, bench_count);
		pb(a, &b, bench_count);
		size--;
	}
	while (b)
		pa(a, &b, bench_count);
}
