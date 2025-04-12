/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:39:08 by medayi            #+#    #+#             */
/*   Updated: 2025/04/11 14:39:08 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	last = *stack_a;
	while (last->next->next)
		last = last->next;
	*stack_a = last->next;
	last->next = NULL;
	(*stack_a)->next = temp;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	last = *stack_b;
	while (last->next->next)
		last = last->next;
	*stack_b = last->next;
	last->next = NULL;
	(*stack_b)->next = temp;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
