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

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("%s\n", "rrr");
}
