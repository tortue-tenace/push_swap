/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:05:12 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 12:21:01 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	ft_compute_disorder(t_list **a)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	mistakes;
	unsigned int	total_pairs;
	unsigned int	size;

	mistakes = 0;
	total_pairs = 0;
	size = ft_lstsize(*a);
	i = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (get_at(*a, i) > get_at(*a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

void	ft_adaptiv_alg(float disorder, t_list **stack_a, t_list **stack_b)
{
	if (disorder < 0.2)
		ft_bubble_sort(stack_a);
	else if (disorder < 0.5)
		ft_chunk_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}
