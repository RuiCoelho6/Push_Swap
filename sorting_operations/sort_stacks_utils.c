/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:48:09 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/29 14:34:36 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	init_index_and_median(*stack_a);
	init_index_and_median(*stack_b);
}

void	rev_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	init_index_and_median(*stack_a);
	init_index_and_median(*stack_b);
}

t_stack_node	*get_cheapest_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_a_for_push(t_stack_node **stack_a, t_stack_node *top_node)
{
	while (*stack_a != top_node)
	{
		if (top_node->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	prep_b_for_push(t_stack_node **stack_b, t_stack_node *top_node)
{
	while (*stack_b != top_node)
	{
		if (top_node->above_median)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
