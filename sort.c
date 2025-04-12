/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:39:08 by medayi            #+#    #+#             */
/*   Updated: 2025/04/11 14:39:08 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	if (ft_lstsize(*stack_a) < 3)
	{
		if (ft_lstsize(*stack_a) == 2
			&& (*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a, 1);
		return ;
	}
	top = (*stack_a)->data;
	middle = (*stack_a)->next->data;
	bottom = (*stack_a)->next->next->data;
	if (top > middle && middle < bottom && top < bottom)
		sa(stack_a, 1);
	else if (top > middle && middle > bottom)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack_a, 1);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack_a, 1);
}

void	rotate_to_min(t_stack **stack_a)
{
	int	min_pos;
	int	size;

	size = ft_lstsize(*stack_a);
	min_pos = find_position(*stack_a, find_min(*stack_a));
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a, 1);
	}
	else
	{
		while (min_pos++ < size)
			rra(stack_a, 1);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 1 || is_sorted(*stack_a))
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a, 1);
	}
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		while (ft_lstsize(*stack_a) > 3)
			pb(stack_a, stack_b);
		sort_three(stack_a);
		while (*stack_b)
		{
			calculate_cost(*stack_a, *stack_b);
			move_cheapest(stack_a, stack_b);
		}
		rotate_to_min(stack_a);
	}
}
