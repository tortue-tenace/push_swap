/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:18:10 by thattal           #+#    #+#             */
/*   Updated: 2026/05/13 16:06:15 by thattal          ###   ########.fr       */
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

static void	ft_rotate_to_max(t_list **b, int max)
{
	int		size;
	int		pos;
	t_list	*tmp;

	size = ft_lstsize(*b);
	pos = 0;
	tmp = *b;
	while (tmp && tmp->data != max)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while (get_data(*b) != max)
			rb(b);
	}
	else
	{
		while (get_data(*b) != max)
			rrb(b);
	}
}

static void	ft_push_chunk(t_list **a, t_list **b, int min_val, int max_val)
{
	int	len;
	int	i;

	len = ft_lstsize(*a);
	i = 0;
	while (i < len && *a)
	{
		if (get_data(*a) >= min_val && get_data(*a) < max_val)
		{
			pb(a, b);
			i++;
		}
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
		ft_rotate_to_max(b, max);
		pa(a, b);
	}
}

void	ft_chunk_sort(t_list **a, t_list **b)
{
	int	size;
	int	chunk_size;
	int	chunk;
	int	min_val;
	int	max_val;

	size = ft_lstsize(*a);
	chunk_size = ft_sqrt_int(size);
	if (chunk_size < 1)
		chunk_size = 1;
	chunk = 0;
	ft_normalize(*a);
	while (*a)
	{
		min_val = chunk_size * chunk;
		max_val = chunk_size * (chunk + 1);
		ft_push_chunk(a, b, min_val, max_val);
		chunk++;
	}
	ft_back_to_a(a, b);
}
