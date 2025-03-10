/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:11:03 by medayi            #+#    #+#             */
/*   Updated: 2025/03/09 06:21:03 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct  s_list
{
    int data;
    struct s_list *next;
} t_list;

void    sa(t_list *a);
void    sa(t_list *b);
void    ss(t_list *a, t_list *b);

t_list  *ft_lstnew(int data);
size_t ft_lstsize(t_list   *lst);

#endif