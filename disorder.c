/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thattal <thattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:18:10 by thattal           #+#    #+#             */
/*   Updated: 2026/05/11 18:06:33 by thattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_compute_disorder(t_list **a)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	mistakes;
	unsigned int	total_pairs;
	unsigned int	size;

	mistakes = 0;
	total_pairs = 0;
	size = ft_lstsize(*a);
	i = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (get_at(*a, i) > get_at(*a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

static int	ft_find_max_b(t_list *b)
{
	int	max;

	max = b->data;
	b = b->next;
	while (b)
	{
		if (b->data > max)
			max = b->data;
		b = b->next;
	}
	return (max);
}

static void	ft_push_chunk(t_list **a, t_list **b, int max_val)
{
	int	len;
	int	i;

	len = ft_lstsize(*a);
	i = 0;
	while (i < len && *a)
	{
		if (get_data(*a) < max_val)
			pb(a, b);
		else
		{
			ra(a);
			i++;
		}
	}
}

static void	ft_back_to_a(t_list **a, t_list **b)
{
	int	max;

	while (*b)
	{
		max = ft_find_max_b(*b);
		while (get_data(*b) != max)
			rb(b);
		pa(a, b);
	}
}

void	ft_chunk_sort(t_list **a, t_list **b)
{
	int	chunk_size;
	int	chunk;

	chunk_size = ft_sqrt_int(ft_lstsize(*a));
	if (chunk_size < 1)
		chunk_size = 1;
	chunk = 0;
	while (*a)
	{
		ft_push_chunk(a, b, chunk_size * (chunk + 1));
		chunk++;
	}
	ft_back_to_a(a, b);
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
        printf("[%d] -> ", get_data(stack)); 
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