/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:40:00 by thattal           #+#    #+#             */
/*   Updated: 2026/05/12 15:40:00 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_save_orig(t_list *a, int size)
{
	int	*orig;
	int	i;

	orig = malloc(sizeof(int) * size);
	if (!orig)
		return (NULL);
	i = 0;
	while (a)
	{
		orig[i++] = a->data;
		a = a->next;
	}
	return (orig);
}

static int	ft_get_rank(t_list *a, int *orig, int idx)
{
	int	rank;
	int	j;

	rank = 0;
	j = 0;
	while (a)
	{
		if (orig[j] < orig[idx])
			rank++;
		a = a->next;
		j++;
	}
	return (rank);
}

static void	ft_normalize(t_list **a)
{
	t_list	*curr;
	int		*orig;
	int		size;
	int		i;

	size = ft_lstsize(*a);
	orig = ft_save_orig(*a, size);
	if (!orig)
		return ;
	curr = *a;
	i = 0;
	while (curr)
	{
		curr->data = ft_get_rank(*a, orig, i);
		curr = curr->next;
		i++;
	}
	free(orig);
}

static int	ft_bit_count(int n)
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

void	ft_radix_sort(t_list **a, t_list **b)
{
	int	size;
	int	bits;
	int	bit;
	int	i;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	ft_normalize(a);
	bits = ft_bit_count(size);
	bit = 0;
	while (bit < bits)
	{
		i = size;
		while (i--)
		{
			if ((get_data(*a) >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}
