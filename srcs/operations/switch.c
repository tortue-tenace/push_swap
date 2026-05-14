/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:21:40 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 12:15:49 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_printf("%s\n", "sa");
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
	ft_printf("%s\n", "sb");
}

void	ss(t_list **a, t_list **b)
{
	if (ft_lstsize(*b) <= 1 || ft_lstsize(*a) <= 1)
		return ;
	sb(b);
	sa(a);
	ft_printf("%s\n", "ss");
}
