/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:53:27 by thattal           #+#    #+#             */
/*   Updated: 2026/05/13 15:54:32 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	has_duplicate(t_list *lst, int val)
{
	while (lst)
	{
		if (lst->data == val)
			return (1);
		lst = lst->next;
	}
	return (0);
}

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

int	main(int ac, char **ag)
{
}*/
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list *liste;
	t_list *listeb;
	t_list *tmp;
	t_list *tmpb;
	int a;
	int b;
	int c;
	int	d;
	int e;

	a = 145;
	b = 65;
	c = 156;
	d = -145;
	e = 600;
	liste = NULL;
	listeb = NULL;
	ft_lstadd_back(&liste, ft_lstnew(a));
	ft_lstadd_back(&liste, ft_lstnew(b));
	ft_lstadd_back(&liste, ft_lstnew(c));
	ft_lstadd_back(&liste, ft_lstnew(d));
	ft_lstadd_back(&liste, ft_lstnew(e));

	ft_printf("Avant : ");
	tmp = liste;
	tmpb = listeb;
	while (tmp)
	{
		ft_printf("%d ->", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");

	//ft_radix_sort(&liste, &listeb);
	//ft_bubble_sort(&liste);
	// selectionsort(&liste, &listeb);
	ft_chunk_sort(&liste, &listeb);

	ft_printf("Apres : ");
	tmp = liste;
	while (tmp)
	{
		ft_printf("%d ->", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");

	tmpb = listeb;
	while (tmpb)
	{
		ft_printf("%d ->", tmpb->data);
		tmpb = tmpb->next;
	}
	ft_printf("NULL\n");

	return (0);
}