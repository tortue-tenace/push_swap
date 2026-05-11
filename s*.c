/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s*.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:21:40 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 16:28:16 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*a) <= 1)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*b) <= 1)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_list **a, t_list **b)
{
	if (ft_lstsize(*b) <= 1 || ft_lstsize(*a) <= 1)
		return ;
	sb(b);
	sa(a);
}
