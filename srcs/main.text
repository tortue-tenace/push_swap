/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:53:27 by thattal           #+#    #+#             */
/*   Updated: 2026/05/14 12:11:31 by thattal          ###   ########.fr       */
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
	int a1 = 145;
	int a2 = 65;
	int a3 = 156;
	int a4 = -145;
	int a5 = 600;
	int a6 = 23;
	int a7 = -78;
	int a8 = 412;
	int a9 = -300;
	int a10 = 89;
	int a11 = -456;
	int a12 = 234;
	int a13 = 17;
	int a14 = -89;
	int a15 = 378;
	int a16 = -234;
	int a17 = 501;
	int a18 = -12;
	int a19 = 67;
	int a20 = -389;
	int a21 = 123;
	int a22 = -422;
	int a23 = 289;
	int a24 = -178;
	//int a25 = 434;

	liste = NULL;
	listeb = NULL;
	ft_lstadd_back(&liste, ft_lstnew(a1));
	ft_lstadd_back(&liste, ft_lstnew(a2));
	ft_lstadd_back(&liste, ft_lstnew(a3));
	ft_lstadd_back(&liste, ft_lstnew(a4));
	ft_lstadd_back(&liste, ft_lstnew(a5));
	ft_lstadd_back(&liste, ft_lstnew(a6));
	ft_lstadd_back(&liste, ft_lstnew(a7));
	ft_lstadd_back(&liste, ft_lstnew(a8));
	ft_lstadd_back(&liste, ft_lstnew(a9));
	ft_lstadd_back(&liste, ft_lstnew(a10));
	ft_lstadd_back(&liste, ft_lstnew(a11));
	ft_lstadd_back(&liste, ft_lstnew(a12));
	ft_lstadd_back(&liste, ft_lstnew(a13));
	ft_lstadd_back(&liste, ft_lstnew(a14));
	ft_lstadd_back(&liste, ft_lstnew(a15));
	ft_lstadd_back(&liste, ft_lstnew(a16));
	ft_lstadd_back(&liste, ft_lstnew(a17));
	ft_lstadd_back(&liste, ft_lstnew(a18));
	ft_lstadd_back(&liste, ft_lstnew(a19));
	ft_lstadd_back(&liste, ft_lstnew(a20));
	ft_lstadd_back(&liste, ft_lstnew(a21));
	ft_lstadd_back(&liste, ft_lstnew(a22));
	ft_lstadd_back(&liste, ft_lstnew(a23));
	ft_lstadd_back(&liste, ft_lstnew(a24));
	//ft_lstadd_back(&liste, ft_lstnew(a25));
	//ft_printf("Avant : ");
	tmp = liste;
	tmpb = listeb;
	while (tmp)
	{
		//t_printf("%d ->", tmp->data);
		tmp = tmp->next;
	}
	//ft_printf("NULL\n");

	// ft_radix_sort(&liste, &listeb);
	// ft_bubble_sort(&liste);
	// selectionsort(&liste, &listeb);
	ft_chunk_sort(&liste, &listeb);

	//ft_printf("Apres : ");
	tmp = liste;
	while (tmp)
	{
		//ft_printf("%d ->", tmp->data);
		tmp = tmp->next;
	}
	//ft_printf("NULL\n");

	tmpb = listeb;
	while (tmpb)
	{
		//ft_printf("%d ->", tmpb->data);
		tmpb = tmpb->next;
	}
	//ft_printf("NULL\n");

	return (0);
}