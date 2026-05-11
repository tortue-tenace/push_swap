/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p*.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 12:19:20 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 12:33:41 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(push_swap **b, push_swap **a)
{
    push_swap  *tmp;

    if (!*b)
		return;
    tmp = (*b)->next;
    (*b)->next = *a;
    *a = *b;
    *b = tmp;
}

void	pb(push_swap **a, push_swap **b)
{
    push_swap  *tmp;

    if (!*a)
		return;
    tmp = (*a)->next;
    (*a)->next = *b;
    *b = *a;
    *a = tmp;
}
