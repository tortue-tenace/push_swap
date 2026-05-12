/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:03:30 by thattal           #+#    #+#             */
/*   Updated: 2026/05/12 15:32:36 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*top;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	top = *a;
	*a = (*a)->next;
	top->next = NULL;
	last = ft_lstlast(*a);
	last->next = top;
	ft_printf("%s\n", "ra");
}

void	rb(t_list **b)
{
	t_list	*top;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	top = *b;
	*b = (*b)->next;
	top->next = NULL;
	last = ft_lstlast(*b);
	last->next = top;
	ft_printf("%s\n", "rb");
}

void	rr(t_list **a, t_list **b)
{
	rb(b);
	rb(a);
	ft_printf("%s\n", "rr");
}

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*beforelast;
	t_list	**temp;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	temp = a;
	while (last->next)
	{
		beforelast = last;
		last = last->next;
	}
	beforelast->next = NULL;
	last->next = *temp;
	*a = last;
	ft_printf("%s\n", "rra");
}

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*beforelast;
	t_list	**temp;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	temp = b;
	while (last->next)
	{
		beforelast = last;
		last = last->next;
	}
	beforelast->next = NULL;
	last->next = *temp;
	*b = last;
	ft_printf("%s\n", "rrb");
}
