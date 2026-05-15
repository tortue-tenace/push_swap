/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:51:26 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 12:00:00 by thattal        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_save_orig(t_list *a, int size)
{
	int	*orig;
	int	i;

	orig = malloc(sizeof(int) * size);
	i = 0;
	while (a)
	{
		orig[i++] = a->data;
		a = a->next;
	}
	return (orig);
}

void	ft_sorted_orig(int *orig, int *sorted, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size)
	{
		sorted[i] = orig[i];
		j = i;
		while (j > 0 && sorted[j - 1] > sorted[j])
		{
			swap = sorted[j];
			sorted[j] = sorted[j - 1];
			sorted[j - 1] = swap;
			j--;
		}
		i++;
	}
}

void	ft_restore(t_list *a, int *sorted)
{
	int	i;

	i = 0;
	while (a)
	{
		a->data = sorted[i];
		i++;
		a = a->next;
	}
}

void	ft_normalize(t_list *a, int *orig, int size)
{
	int	ki;
	int	kj;

	ki = 0;
	while (a)
	{
		kj = 0;
		a->data = 0;
		while (kj < size)
		{
			if (orig[kj] < orig[ki])
				a->data++;
			kj++;
		}
		a = a->next;
		ki++;
	}
}
