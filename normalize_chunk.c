/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:51:26 by thattal           #+#    #+#             */
/*   Updated: 2026/05/13 16:02:43 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_save_orig(t_list *a, int size)
{
	int		*orig;
	int		i;

	orig = malloc(sizeof(int) * size);
	i = 0;
	while (a)
	{
		orig[i++] = a->data;
		a = a->next;
	}
	return (orig);
}

void	ft_normalize(t_list *a)
{
	int		*orig;
	int		size;
	int		ki;
	int		kj;

	size = ft_lstsize(a);
	orig = ft_save_orig(a, size);
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
	free(orig);
}
