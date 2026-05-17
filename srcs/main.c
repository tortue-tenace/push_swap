/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurie <lmurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:01:35 by lmurie            #+#    #+#             */
/*   Updated: 2026/05/17 14:59:13 by lmurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	ft_run_algo(int flag, t_list **liste,
				t_list **listeb, t_count *bench_count)
{
	if (flag == 1)
		ft_bubble_sort(liste, bench_count);
	else if (flag == 2)
		ft_chunk_sort(liste, listeb, bench_count);
	else if (flag == 3)
		ft_radix_sort(liste, listeb, bench_count);
	else
		ft_adaptiv_alg(ft_compute_disorder(liste),
			liste, listeb, bench_count);
}

int	main(int argc, char *argv[])
{
	t_list	*liste;
	t_list	*listeb;
	int		flags[2];
	t_count	bench_count;

	init_bench_count(&bench_count);
	listeb = NULL;
	if (argc == 1)
		return (0);
	detectflags(argc, argv, flags);
	bench_count.algo = flags[0];
	liste = addarg(argc, argv);
	bench_count.disorder = ft_compute_disorder(&liste) * 100.0f;
	if (is_sorted(liste) == 1 && flags[1] == 0)
	{
		ft_lstclear(&liste);
		return (0);
	}
	ft_run_algo(flags[0], &liste, &listeb, &bench_count);
	ft_lstclear(&liste);
	ft_lstclear(&listeb);
	if (flags[1] == 1)
		ft_benchmark(&bench_count);
	return (0);
}
