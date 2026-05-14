/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:59:26 by lmurie            #+#    #+#             */
/*   Updated: 2026/05/13 15:10:01 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min (t_list **a)
{
	int minvalue;
	int size;
	int	i;
	t_list **temp;

	i = 0;
	temp = a;
	size = ft_lstsize(*a);
	minvalue = (*a)->data;
	while (i < size - 1)
	{
		if ((*temp)->data < minvalue)
			minvalue = (*temp)->data;
		i++;
		(temp) = &(*temp)->next;
	}
	return (minvalue);
}

int max (t_list **a)
{
	int maxvalue;
	int size;
	int	i;
	t_list **temp;

	i = 0;
	temp = a;
	size = ft_lstsize(*a);
	maxvalue = (*a)->data;
	while (i < size)
	{
		if ((*temp)->data > maxvalue)
			maxvalue = (*temp)->data;
		i++;
		(temp) = &(*temp)->next;
	}
	return (maxvalue);
}


char	*decimaltobinary(int a)
{
	char *tab;
	int	i;

	i = 0;
	tab=malloc(sizeof(char) * 100);
	while (a != 0)
	{
		tab[i] = a%2 + '0';
		printf("%d", a%2);
		a /= 2;
		i++;

	}
	tab[i] = '\0';
	return (tab);
}
void adddel_min(t_list **a, int min, int sorted)
{
	t_list *temp;

	temp = (*a);
	if (sorted == 0)
	{
		while (temp)
		{
			(temp)->data -= min;
			(temp) = (temp)->next;
		}
	}
	else 
	{ 
		while (temp)
		{
			(temp)->data += min;
			(temp) = (temp)->next;
		}
	}
}

void ft_radix_sort(t_list **a, t_list **b)
{
	int i;
	int nbdigits;
	int size;
	int	j;

	
	int temp;
	
	temp = 0;
	
	i = 0;
	j = 0;
	size = ft_lstsize(*a);
	if (min(a) < 0)
	{
		temp = min(a);
		adddel_min(a, temp, j);
	}
	
	nbdigits = ft_strlen(decimaltobinary(max(a)));
	while (j < nbdigits)
	{
		while (i < size)
		{
			if (((*a)->data >> j) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b)
			pa(a,b);
		i = 0;
		j++;
	}
	
	if (temp < 0)
		adddel_min(a, temp, j);
	
}
