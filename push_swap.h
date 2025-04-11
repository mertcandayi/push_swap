/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:39:08 by medayi            #+#    #+#             */
/*   Updated: 2025/04/11 14:39:08 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	ft_lstadd_back(t_stack **stack, t_stack *new);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstnew(int data);
int	ft_lstsize(t_stack *stack);


#endif