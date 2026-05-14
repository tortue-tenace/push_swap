/* ************************************************************************** */
/*	 */
/*	 :::	 ::::::::   */
/*   utils.c	    :+:	 :+:    :+:   */
/*	  +:+ +:+	    +:+	*/
/*   By: thattal <thattal@student.42.fr>	  +#+  +:+	  +#+	   */
/*	   +#+#+#+#+#+   +#+	 */
/*   Created: 2026/05/11 17:52:39 by thattal	 #+#    #+#	   */
/*   Updated: 2026/05/11 17:55:33 by thattal	###   ########.fr	  */
/*	 */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

int	ft_sqrt_int(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}
