/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurie <lmurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:59:26 by lmurie            #+#    #+#             */
/*   Updated: 2026/05/15 12:50:01 by lmurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **a)
{
	int		min;
	t_list	*tmp;

	tmp = *a;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

static int	count_max_bits(t_list **a)
{
	int		n;
	int		bits;
	t_list	*tmp;

	tmp = *a;
	n = tmp->data;
	while (tmp)
	{
		if (tmp->data > n)
			n = tmp->data;
		tmp = tmp->next;
	}
	bits = 0;
	while (n > 0)
	{
		bits++;
		n >>= 1;
	}
	return (bits);
}

static void	adjust_min(t_list **a, int min_val, int restore)
{
	t_list	*tmp;

	tmp = *a;
	if (!restore)
	{
		while (tmp)
		{
			tmp->data -= min_val;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			tmp->data += min_val;
			tmp = tmp->next;
		}
	}
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
	int	j;
	int	nbdigits;
	int	min_val;

	j = 0;
	min_val = 0;
	if (get_min(a) < 0)
	{
		min_val = get_min(a);
		adjust_min(a, min_val, 0);
	}
	nbdigits = count_max_bits(a);
	while (j < nbdigits)
	{
		ft_radix_pass(a, b, j, bench_count);
		j++;
	}
	if (min_val < 0)
		adjust_min(a, min_val, 1);
}
