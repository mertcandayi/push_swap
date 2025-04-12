/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:34:26 by medayi            #+#    #+#             */
/*   Updated: 2025/04/12 17:34:37 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;
	int cost_a;
	int cost_b;

	cheapest = find_cheapest(*stack_b);
	if (!cheapest)
		return ;
	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	do_rotations(stack_a, stack_b, cost_a, cost_b);
	pa(stack_a, stack_b);
}