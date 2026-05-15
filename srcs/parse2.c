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
	int		i;
	int		sign;
	long	n;

	sign = 1;
	n = 0;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		n = n * 10 + (s[i++] - '0');
		if ((sign == 1 && n > 2147483647L)
			|| (sign == -1 && n > 2147483648L))
			return (0);
	}
	return (1);
}

static void	error_exit(t_list **liste)
{
	ft_lstclear(liste);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	check_dup(t_list **liste, char *argv[], int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (!isflag(argv[j]) && ft_atoi(argv[i]) == ft_atoi(argv[j]))
			error_exit(liste);
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
			error_exit(&liste);
		check_dup(&liste, argv, i);
		ft_lstadd_back(&liste, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (liste);
}
