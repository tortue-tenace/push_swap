/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:18:10 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 12:15:27 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void ft_push_chunk(t_list **a, t_list **b, int min_val, int max_val)
{
    int len;
    int i;

    len = ft_lstsize(*a);
    i = 0;
    while (i < len && *a)
    {
        if (get_data(*a) >= min_val && get_data(*a) < max_val)
        {
            pb(a, b);
            len--;
            if (*b && (*b)->next && get_data(*b) < (*b)->next->data)
                rb(b);
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

void	ft_chunk_sort(t_list **a, t_list **b)
{
	int	size;
	int	chunk_size;
	int	chunk;
	int	min_val;
	int	max_val;
	int	*sorted;

	size = ft_lstsize(*a);
	sorted = ft_prepare(*a, size);
	chunk_size = ft_chunk_size(size);
	chunk = 0;
	while (*a)
	{
		min_val = chunk_size * chunk;
		max_val = chunk_size * (chunk + 1);
		ft_push_chunk(a, b, min_val, max_val);
		chunk++;
	}
	ft_back_to_a(a, b);
	ft_restore(*a, sorted);
	free(sorted);
}
