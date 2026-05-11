/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:18:10 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 17:22:51 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_at(t_list *a, int index)
{
	while (index--)
		a = a->next;
	return (a->data);
}

int     get_data(t_list *a)
{
    if (!a)
        return (0);
    return (a->data);
}

int     ft_sqrt_int(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	get_data(t_list **a)
{
	return ((*a)->data);
}

unsigned int	ft_compute_disorder(t_list **a)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	mistakes;
	unsigned int	total_pairs;

	mistakes = 0;
	i = 0;
	total_pairs = 0;
	while (i <= ft_lstsize(*a) - 1)
	{
		j = i + 1;
		while (j <= ft_lstsize(*a))
		{
			total_pairs += 1;
			if (get_at(a, i) > get_at(a, j))
				mistakes += 1;
		}
		i++;
	}
	return ((float)(mistakes / total_pairs));
}

void    ft_chunk_sort(t_list **a, t_list **b)
{
	int	chunk_size;
	int	chunk;
	int	size;

	size = ft_lstsize(*a);
	chunk_size = ft_sqrt_int(size);
	chunk = 0;
	while (*a)
	{
		if (get_data(*a) < chunk_size * (chunk + 1))
		{
			pb(a, b);
			chunk++;
		}
		else
			ra(a);
	}
	while (*b)
		pa(a, b);
}
#include <stdio.h>

void print_stack(char *name, t_list *stack)
{
    printf("Stack %s: ", name);
    if (!stack)
    {
        printf("(vide)\n");
        return;
    }
    while (stack)
    {
        // On utilise ici get_value si c'est ta fonction pour récupérer la valeur,
        // sinon tu peux remplacer par stack->value.
        printf("[%d] -> ", get_value(stack)); 
        stack = stack->next;
    }
    printf("NULL\n");
}

int main(void)
{
    // 1. Déclaration des pointeurs de tête de piles
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    // 2. Déclaration et allocation manuelle des nœuds pour la pile A
    t_list *n1 = malloc(sizeof(t_list));
    t_list *n2 = malloc(sizeof(t_list));
    t_list *n3 = malloc(sizeof(t_list));
    t_list *n4 = malloc(sizeof(t_list));
    t_list *n5 = malloc(sizeof(t_list));

    if (!n1 || !n2 || !n3 || !n4 || !n5)
    {
        printf("Erreur d'allocation mémoire\n");
        return (1);
    }

    // 3. Attribution des valeurs (get_data)
    n1->data = 3;
    n2->data = 1;
    n3->data = 4;
    n4->data = 0;
    n5->data = 2;

    // 4. Chaînage manuel des éléments pour former la pile A
    stack_a = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL; // Fin de la liste

    // 5. Affichage avant le tri
    printf("=== ÉTAT INITIAL ===\n");
    print_stack("A", stack_a);
    print_stack("B", stack_b);
    printf("\n--- Exécution de ft_chunk_sort ---\n");

    // 6. Appel de ton tri
    ft_chunk_sort(&stack_a, &stack_b);

    // 7. Affichage après le tri
    printf("\n=== ÉTAT FINAL ===\n");
    print_stack("A", stack_a);
    print_stack("B", stack_b);

    // 8. Libération manuelle de la mémoire pour éviter les leaks
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return (0);
}