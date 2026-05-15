/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:03:30 by thattal           #+#    #+#             */
/*   Updated: 2026/05/15 13:27:15 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **a, t_count *bench_count)
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
	bench_count->ra++;
	bench_count->total++;
}

void	rb(t_list **b, t_count *bench_count)
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
	bench_count->rb++;
	bench_count->total++;
}

void	rr(t_list **a, t_list **b, t_count *bench_count)
{
	rb(b, bench_count);
	ra(a, bench_count);
	ft_printf("%s\n", "rr");
	bench_count->rr++;
	bench_count->rb--;
	bench_count->ra--;
	bench_count->total = bench_count->total - 1;
}

void	rra(t_list **a, t_count *bench_count)
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
	bench_count->rra++;
	bench_count->total++;
}

void	rrb(t_list **b, t_count *bench_count)
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
	bench_count->rrb++;
	bench_count->total++;
}
