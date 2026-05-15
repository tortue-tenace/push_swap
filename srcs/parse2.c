/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:00:00 by thattal           #+#    #+#             */
/*   Updated: 2026/05/15 17:00:00 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_int(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i] || s[i] == '-' || s[i] == '+')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	check_dup(t_list **liste, char *argv[], int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (!isflag(argv[j]) && ft_atoi(argv[i]) == ft_atoi(argv[j]))
		{
			ft_lstclear(liste);
			ft_printf("Error\n");
			exit(1);
		}
		j++;
	}
}

t_list	*addarg(int argc, char *argv[])
{
	t_list	*liste;
	int		i;

	i = 1;
	liste = NULL;
	while (i < argc)
	{
		if (isflag(argv[i]))
		{
			i++;
			continue ;
		}
		if (!is_valid_int(argv[i]))
		{
			ft_lstclear(&liste);
			ft_printf("Error\n");
			exit(1);
		}
		check_dup(&liste, argv, i);
		ft_lstadd_back(&liste, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (liste);
}
