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

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_lstnew(int data);
void				ft_lstadd_back(t_stack **stack, t_stack *new);
void				ft_lstadd_front(t_stack **stack, t_stack *new);
int					ft_lstsize(t_stack *stack);

void				sa(t_stack **stack_a, int print);
void				sb(t_stack **stack_b, int print);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a, int print);
void				rb(t_stack **stack_b, int print);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_b, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b);

void				sort(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a);
int					is_sorted(t_stack *stack);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					find_position(t_stack *stack, int num);
void				calculate_cost(t_stack *stack_a, t_stack *stack_b);
void				rotate_to_min(t_stack **stack_a);

int					ft_isspace(char c);
int					ft_isdigit(int c);
long				ft_atol(const char *str);
int					ft_is_valid_integer(char *str);
int					ft_has_duplicate(t_stack *stack, int num);
char				**ft_split(char const *s, char c);
void				ft_free_split(char **split);
void				ft_error(void);
void				free_stack(t_stack **stack);

int					parse_args(int argc, char **argv, t_stack **stack_a);
int					process_arg(char *arg, t_stack **stack_a);
int					add_number_to_stack(t_stack **stack_a, int num);

int					find_target_position(t_stack *stack_a, int b_num);
t_stack				*find_cheapest(t_stack *stack_b);
void				do_rotations(t_stack **stack_a, t_stack **stack_b,
						int cost_a, int cost_b);
void				move_cheapest(t_stack **stack_a, t_stack **stack_b);

#endif