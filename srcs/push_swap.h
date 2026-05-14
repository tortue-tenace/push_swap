/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:13:18 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 15:10:22 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_count
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_count;

void				ft_bubble_sort(t_list **a, t_count *bench_count);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					get_at(t_list *a, int index);
float				ft_compute_disorder(t_list **a);
void				pa(t_list **a, t_list **b, t_count *bench_count);
void				pb(t_list **a, t_list **b, t_count *bench_count);
void				ss(t_list **a, t_list **b, t_count *bench_count);
void				sb(t_list **b, t_count *bench_count);
void				sa(t_list **a, t_count *bench_count);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
int					ft_sqrt_int(int n);
int					get_at(t_list *a, int index);
int					get_data(t_list *a);
void				ra(t_list **a, t_count *bench_count);
void				rb(t_list **b, t_count *bench_count);
void				rr(t_list **a, t_list **b, t_count *bench_count);
void				rra(t_list **a, t_count *bench_count);
void				rrb(t_list **b, t_count *bench_count);
void				rrr(t_list **a, t_list **b, t_count *bench_count);
void				ft_chunk_sort(t_list **a, t_list **b, t_count *bench_count);
void				ft_radix_sort(t_list **a, t_list **b, t_count *bench_count);
void				ft_adaptiv_alg(float disorder, t_list **stack_a,
						t_list **stack_b, t_count *bench_count);
t_list				*ft_lstnew(int number);
int					ft_strlen(char *str);
void				ft_normalize(t_list *a, int *orig, int size);
int					*ft_save_orig(t_list *a, int size);
void				ft_sorted_orig(int *orig, int *sorted, int size);
void				ft_restore(t_list *a, int *sorted);
void				ft_normalize(t_list *a, int *orig, int size);
void				ft_back_to_a(t_list **a, t_list **b, t_count *bench_count);
void				ft_push_chunk(t_list **a, t_list **b, int min_val,
						int max_val, t_count *bench_count);
void				ft_rotate_to_max(t_list **b, int max, t_count *bench_count);
int					ft_find_max_b(t_list *b);
void				init_bench_count(t_count *bench_count);
void				ft_benchmark(t_count *bench_count);

#endif