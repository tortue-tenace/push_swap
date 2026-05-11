/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:21:40 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 12:16:49 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(push_swap **a)
{
	if (ft_lstsize(*a) <= 1)
		return ;
	push_swap	*first;
	push_swap	*second;

	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second; 
}

void	sb(push_swap **b)
{
	if (ft_lstsize(*b) <= 1)
		return ;
	push_swap	*first;
	push_swap	*second;

	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second; 
}

void	ss(push_swap **a, push_swap **b)
{
	if (ft_lstsize(*b) <= 1 || ft_lstsize(*a) <= 1)
		return ;
	sb(b);
	sa(a);
}
