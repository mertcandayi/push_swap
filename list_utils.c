#include "push_swap.h"

t_list  *ft_lstnew(int data)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if(!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

int ft_lstsize(t_list   *lst)
{
    size_t  size;

    size = 0;
    while (lst)
    {
        lst = lst->next;
        size++;
    }
    return(size);
}