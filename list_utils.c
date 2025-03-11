/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:11:03 by medayi            #+#    #+#             */
/*   Updated: 2025/03/09 06:27:30 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

size_t ft_lstsize(t_list   *lst)
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