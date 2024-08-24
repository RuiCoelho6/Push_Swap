/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:00 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/24 12:11:16 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_stack_node **stack_a,
						t_stack_node **stack_b,
						t_stack_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rr(stack_a, stack_b, false);
	set_index_median(*stack_a);
	set_index_median(*stack_b);
}

static void	rev_rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b,
							t_stack_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rrr(stack_a, stack_b, false);
	set_index_median(*stack_a);
	set_index_median(*stack_b);
}

static void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_a_for_push(stack_a, cheapest_node);
	prep_b_for_push(stack_b, cheapest_node->target_node);
	pb(stack_b, stack_a, false);
}

static void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	prep_a_for_push(stack_a, (*stack_b)->target_node);
	pa(stack_a, stack_b, false);
}

void	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_a_len;

	stack_a_len = ft_stack_len(*stack_a);
	if (stack_a_len-- > 3 && !ft_stack_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	if (stack_a_len-- > 3 && !ft_stack_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (stack_a_len-- > 3 && !ft_stack_sorted(*stack_a))
	{
		init_a_nodes(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_b_nodes(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_index_median(*stack_a);
	min_on_top(stack_a);
}
