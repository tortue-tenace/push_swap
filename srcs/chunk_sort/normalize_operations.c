/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:53:38 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 14:55:27 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_max_b(t_list *b)
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

void	ft_rotate_to_max(t_list **b, int max, t_count *bench_count)
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
			rb(b, bench_count);
	}
	else
	{
		while (get_data(*b) != max)
			rrb(b, bench_count);
	}
}

void ft_push_chunk(t_list **a, t_list **b, int min_val, int max_val, t_count *bench_count)
{
    int len;
    int i;

    len = ft_lstsize(*a);
    i = 0;
    while (i < len && *a)
    {
        if (get_data(*a) >= min_val && get_data(*a) < max_val)
        {
            pb(a, b, bench_count);
            len--;
            if (*b && (*b)->next && get_data(*b) < (*b)->next->data)
                rb(b, bench_count);
        }
        else
        {
            ra(a, bench_count);
            i++;
        }
    }
}

void	ft_back_to_a(t_list **a, t_list **b, t_count *bench_count)
{
	int	max;

	while (*b)
	{
		max = ft_find_max_b(*b);
		ft_rotate_to_max(b, max, bench_count);
		pa(a, b, bench_count);
	}
}
