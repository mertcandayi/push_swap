/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:34:12 by medayi            #+#    #+#             */
/*   Updated: 2025/04/12 17:34:15 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;
	int	pos;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		pos = find_position(stack_b, stack_b->data);
		stack_b->cost_b = pos;
		if (pos > size_b / 2)
			stack_b->cost_b = -(size_b - pos);
		pos = find_target_position(stack_a, stack_b->data);
		stack_b->cost_a = pos;
		if (pos > size_a / 2)
			stack_b->cost_a = -(size_a - pos);
		stack_b = stack_b->next;
	}
}

t_stack	*find_cheapest(t_stack *stack_b)
{
	t_stack	*cheapest;
	int		lowest_cost;
	int		cost;

	if (!stack_b)
		return (NULL);
	cheapest = stack_b;
	lowest_cost = 2147483647;
	while (stack_b)
	{
		cost = abs(stack_b->cost_a) + abs(stack_b->cost_b);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			cheapest = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest);
}

void	do_rotations(t_stack **stack_a, t_stack **stack_b, int cost_a,
		int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(stack_a, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(stack_a, 1);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(stack_b, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stack_b, 1);
		cost_b++;
	}
}