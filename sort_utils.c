/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:33:34 by medayi            #+#    #+#             */
/*   Updated: 2025/04/12 17:33:50 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stack *stack, int num)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->data == num)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	find_target_position(t_stack *stack_a, int b_num)
{
	t_stack *temp;
	int target_pos;
	int closest_bigger;

	temp = stack_a;
	target_pos = 0;
	closest_bigger = 2147483647;
	while (temp)
	{
		if (temp->data > b_num && temp->data < closest_bigger)
		{
			closest_bigger = temp->data;
			target_pos = find_position(stack_a, temp->data);
		}
		temp = temp->next;
	}
	if (closest_bigger == 2147483647)
		target_pos = find_position(stack_a, find_min(stack_a));
	return (target_pos);
}