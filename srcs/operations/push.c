/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 12:19:20 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 13:19:55 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **a, t_list **b, t_count	*bench_count)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_printf("%s\n", "pa");
	bench_count->pa++;
	bench_count->total++;
}

void	pb(t_list **a, t_list **b, t_count	*bench_count)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_printf("%s\n", "pb");
	bench_count->pb++;
	bench_count->total++;
}
