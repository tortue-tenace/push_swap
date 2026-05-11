/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:13:18 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 14:48:53 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>

typedef struct t_push_swap
{
	int					data;
	struct push_swap	*next;
}	t_push_swap;

int	get_at(t_push_swap *a, int index);
unsigned int	ft_compute_disorder(t_push_swap **a);
void	pa(t_push_swap **b, t_push_swap **a);
void	pb(t_push_swap **a, t_push_swap **b);
void	ss(t_push_swap **a, t_push_swap **b);
void	sb(t_push_swap **b);
void	sa(t_push_swap **a);

#endif