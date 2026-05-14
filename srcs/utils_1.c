/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   utils_1.c	  :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: thattal <thattal@student.42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2026/05/11 17:56:49 by thattal	   #+#	#+#	 */
/*   Updated: 2026/05/12 15:29:15 by thattal	  ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "push_swap.h"

int	get_at(t_list *a, int index)
{
	while (index--)
		a = a->next;
	return (a->data);
}

int	get_data(t_list *a)
{
	if (!a)
		return (0);
	return (a->data);
}

void	rrr(t_list **a, t_list **b, t_count *bench_count)
{
	rra(a, bench_count);
	rrb(b, bench_count);
	ft_printf("%s\n", "rrr");
	bench_count->rrr++;
	bench_count->rra--;
	bench_count->rrb--;
	bench_count->total = bench_count->total - 1;
}

t_list	*ft_lstnew(int number)
{
	t_list		*new;
	static int	i = 0;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = number;
	new->index = i;
	i++;
	new->next = NULL;
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}