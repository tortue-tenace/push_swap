/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:01:35 by lmurie            #+#    #+#             */
/*   Updated: 2026/05/14 15:50:36 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
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

int	isflag(char *s)
{
	if (ft_strncmp(s, "--simple", ft_strlen(s)) == 0)
		return (1);
	else if (ft_strncmp(s, "--medium", ft_strlen(s)) == 0)
		return (1);
	else if (ft_strncmp(s, "--complex", ft_strlen(s)) == 0)
		return (1);
	else if (ft_strncmp(s, "--adaptive", ft_strlen(s)) == 0)
		return (1);
	else if (ft_strncmp(s, "--bench", ft_strlen(s)) == 0)
		return (1);
	else
		return (0);
}

void	detectflags(int argc, char *argv[], int flags[1])
{
	int	i;

	i = 1;
	flags[0] = 0;
	flags[1] = 0;
	while (i < argc && isflag(argv[i]))
	{
		if (ft_strncmp(argv[i], "--simple", ft_strlen(argv[i])) == 0)
			flags[0] = 1;
		else if (ft_strncmp(argv[i], "--medium", ft_strlen(argv[i])) == 0)
			flags[0] = 2;
		else if (ft_strncmp(argv[i], "--complex", ft_strlen(argv[i])) == 0)
			flags[0] = 3;
		else if (ft_strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0)
			flags[1] = 1;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*liste;
	t_list	*listeb;
	t_list	*tmp;
	t_list	*tmpb;
	t_count	bench_count;
	int		i;
	int		j;
	int		flags[1];

	liste = NULL;
	listeb = NULL;
	i = 1;
	j = 1;
	if (argc == 1)
		printf("Il faut mettre au moins un arg \n");
	detectflags(argc, argv, flags);
	while (i < argc)
	{
		j = 1;
		while (j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				printf("il y a un nombre en double /n");
				return (0);
			}
			j++;
		}
		ft_lstadd_back(&liste, ft_lstnew(ft_atoi(argv[i])));
		j = i;
		i++;
	}
	ft_printf("Avant : ");
	tmp = liste;
	tmpb = listeb;
	while (tmp)
	{
		ft_printf("%d ->", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
	if (flags[0] == 1)
		ft_bubble_sort(&liste, &bench_count);
	if (flags[0] == 2)
		ft_chunk_sort(&liste, &listeb, &bench_count);
	if (flags[0] == 3)
		ft_radix_sort(&liste, &listeb, &bench_count);
	else 
		ft_adaptiv_alg(ft_compute_disorder(&liste), &liste, &listeb, &bench_count);
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
	if (flags[1] == 1)
		ft_benchmark(&bench_count);
	return (0);
}
