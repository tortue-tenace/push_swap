/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:00:00 by thattal           #+#    #+#             */
/*   Updated: 2026/05/15 17:00:00 by thattal          ###   ########.fr       */
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
	return (0);
}

void	detectflags(int argc, char *argv[], int flags[2])
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
