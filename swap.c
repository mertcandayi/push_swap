/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:39:08 by medayi            #+#    #+#             */
/*   Updated: 2025/04/11 14:39:08 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int print)
{
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	if (print)
		write (1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write (1, "ss\n", 3);
}