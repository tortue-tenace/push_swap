#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int             value;
    struct s_list   *next;
}   t_list;

int     ft_lstsize(t_list *a)
{
    int size;

    size = 0;
    while (a)
    {
        size++;
        a = a->next;
    }
    return (size);
}

void    sa(t_list **a)
{
    t_list  *first;
    t_list  *second;

    if (ft_lstsize(*a) <= 1)
        return ;
    first        = *a;
    second       = (*a)->next;
    first->next  = second->next;
    second->next = first;
    *a           = second;
}

void    print_stack(char *name, t_list *s)
{
    printf("%s : ", name);
    while (s)
    {
        printf("[%d] ", s->value);
        s = s->next;
    }
    printf("\n");
}

void    push_front(t_list **stack, int value)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    node->value = value;
    node->next = *stack;
    *stack = node;
}

int main(void)
{
    t_list *a;

    a = NULL;

    // Test 1 : liste vide
    printf("=== Test 1 : liste vide ===\n");
    sa(&a);
    print_stack("a", a);

    // Test 2 : un seul element
    printf("\n=== Test 2 : un seul element ===\n");
    push_front(&a, 10);
    print_stack("avant", a);
    sa(&a);
    print_stack("apres", a);

    // Test 3 : deux elements
    printf("\n=== Test 3 : deux elements ===\n");
    push_front(&a, 20);
    print_stack("avant", a);
    sa(&a);
    print_stack("apres", a);

    // Test 4 : trois elements
    printf("\n=== Test 4 : trois elements ===\n");
    push_front(&a, 30);
    print_stack("avant", a);
    sa(&a);
    print_stack("apres", a);

    return (0);
}