/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:35:56 by thattal           #+#    #+#             */
/*   Updated: 2026/05/15 14:56:46 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bubble_sort(t_list **a, t_count *bench_count)
{
	t_list	**temp;
	int		i;
	int		size;
	int		flag;

	i = 0;
	flag = 0;
	temp = a;
	size = ft_lstsize(*a);
	while (flag < size - 1)
	{
		while (i < size - 1)
		{
			if ((*temp)->data > (*temp)->next->data)
				sa(temp, bench_count);
			temp = &(*temp)->next;
			i++;
		}
		temp = a;
		i = 0;
		flag++;
	}
}
