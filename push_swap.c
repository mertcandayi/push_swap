/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:33:39 by medayi            #+#    #+#             */
/*   Updated: 2025/04/11 20:33:39 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_number_to_stack(t_stack **stack_a, int num)
{
	t_stack	*new;

	if (ft_has_duplicate(*stack_a, num))
		return (0);
	new = ft_lstnew(num);
	if (!new)
		return (0);
	ft_lstadd_back(stack_a, new);
	return (1);
}

int	process_arg(char *arg, t_stack **stack_a)
{
	char	**nums;
	int		i;
	int		num;

	nums = ft_split(arg, ' ');
	if (!nums)
		return (0);
	i = 0;
	while (nums[i])
	{
		if (!ft_is_valid_integer(nums[i]))
		{
			ft_free_split(nums);
			return (0);
		}
		num = (int)ft_atol(nums[i]);
		if (!add_number_to_stack(stack_a, num))
		{
			ft_free_split(nums);
			return (0);
		}
		i++;
	}
	ft_free_split(nums);
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	parse_args(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	*stack_a = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!process_arg(argv[i], stack_a))
		{
			free_stack(stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!parse_args(argc, argv, &stack_a))
	{
		ft_error();
		return (1);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
