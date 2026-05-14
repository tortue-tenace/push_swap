/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:13:18 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 12:20:24 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct t_list
{
	int				data;
	int				index;
	struct t_list	*next;
}					t_list;

void				ft_bubble_sort(t_list **a);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					get_at(t_list *a, int index);
float				ft_compute_disorder(t_list **a);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				ss(t_list **a, t_list **b);
void				sb(t_list **b);
void				sa(t_list **a);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
int					ft_sqrt_int(int n);
int					get_at(t_list *a, int index);
int					get_data(t_list *a);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
void				ft_chunk_sort(t_list **a, t_list **b);
void				ft_radix_sort(t_list **a, t_list **b);
void				ft_adaptiv_alg(float disorder, t_list **stack_a,
						t_list **stack_b);
t_list				*ft_lstnew(int number);
int					ft_strlen(char *str);
void				ft_normalize(t_list *a, int *orig, int size);
int					*ft_save_orig(t_list *a, int size);
void				ft_sorted_orig(int *orig, int *sorted, int size);
void				ft_restore(t_list *a, int *sorted);
void				ft_normalize(t_list *a, int *orig, int size);

#endif