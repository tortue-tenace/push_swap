/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:18:10 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 15:31:02 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_at(t_push_swap *a, int index)
{
	while (index--)
		a = a->next;
	return (a->data);
}

int     ft_sqrt_int(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

unsigned int	ft_compute_disorder(t_push_swap **a)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	mistakes;
	unsigned int	total_pairs;

	mistakes = 0;
	i = 0;
	total_pairs = 0;
	while (i <= ft_lstsize(*a) - 1)
	{
		j = i + 1;
		while (j <= ft_lstsize(*a))
		{
			total_pairs += 1;
			if (get_at(a, i) > get_at(a, j))
				mistakes += 1;
		}
		i++;
	}
	return ((float)(mistakes / total_pairs));
}

void    ft_chunk_sort(t_push_swap **a, t_push_swap **b)
{
	int	chunk_size;
	int	chunk;
	int	size;

	size = ft_lstsize(*a);
	chunk_size = ft_sqrt_int(size);
	chunk = 0;
	while (*a)
	{
		if (get_value(*a) < chunk_size * (chunk + 1))
		{
			pb(a, b);
			chunk++;
		}
		else
			ra(a);
	}
	while (*b)
		pa(a, b);
}
