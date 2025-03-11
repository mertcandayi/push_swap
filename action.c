/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:11:03 by medayi            #+#    #+#             */
/*   Updated: 2025/03/09 06:11:03 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list *a, int print)
{
    int tmp;
    size_t size;

    size = ft_lstsize(a);
    if(size > 1)
    {
        tmp = a->data;
        a->data = a->next->data;
        a->next->data = tmp;
        if (print == 1)
            write(1, "sa\n", 3);
    }
}

void    sb(t_list *b, int print)
{
    int tmp;
    size_t size;

    size = ft_lstsize(b);
    if(size > 1)
    {
        tmp = b->data;
        b->data = b->next->data;
        b->next->data = tmp;
        if (print == 1)
            write(1, "sb\n", 3);
    }
}

void    ss(t_list *a, t_list *b)
{
    sa(a, 0);
    sb(b, 0);
    write(1, "ss\n", 3);
}