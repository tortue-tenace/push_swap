/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s*.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:21:40 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 12:50:57 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap **a)
{
	t_push_swap	*first;
	t_push_swap	*second;

	if (ft_lstsize(*a) <= 1)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_push_swap **b)
{
	t_push_swap	*first;
	t_push_swap	*second;

	if (ft_lstsize(*b) <= 1)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_push_swap **a, t_push_swap **b)
{
	if (ft_lstsize(*b) <= 1 || ft_lstsize(*a) <= 1)
		return ;
	sb(b);
	sa(a);
}
