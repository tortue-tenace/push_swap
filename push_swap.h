/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:13:18 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 18:04:33 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct t_list
{
	int					data;
	struct t_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
int	get_at(t_list *a, int index);
unsigned int	ft_compute_disorder(t_list **a);
void	pa(t_list **b, t_list **a);
void	pb(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
void	sb(t_list **b);
void	sa(t_list **a);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);
int     ft_sqrt_int(int n);
int	get_at(t_list *a, int index);
int     get_data(t_list *a);
void    ra(t_list **a);

#endif