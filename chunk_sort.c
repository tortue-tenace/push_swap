/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:18:10 by thattal           #+#    #+#             */
/*   Updated: 2026/05/12 13:18:52 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_max_b(t_list *b)
{
	int	max;

	max = b->data;
	b = b->next;
	while (b)
	{
		if (b->data > max)
			max = b->data;
		b = b->next;
	}
	return (max);
}

static void	ft_push_chunk(t_list **a, t_list **b, int max_val)
{
	int	len;
	int	i;

	len = ft_lstsize(*a);
	i = 0;
	while (i < len && *a)
	{
		if (get_data(*a) < max_val)
			pb(a, b);
		else
		{
			ra(a);
			i++;
		}
	}
}

static void	ft_back_to_a(t_list **a, t_list **b)
{
	int	max;

	while (*b)
	{
		max = ft_find_max_b(*b);
		while (get_data(*b) != max)
			rb(b);
		pa(a, b);
	}
}

void	ft_chunk_sort(t_list **a, t_list **b)
{
	int	chunk_size;
	int	chunk;

	chunk_size = ft_sqrt_int(ft_lstsize(*a));
	if (chunk_size < 1)
		chunk_size = 1;
	chunk = 0;
	while (*a)
	{
		ft_push_chunk(a, b, chunk_size * (chunk + 1));
		chunk++;
	}
	ft_back_to_a(a, b);
}
