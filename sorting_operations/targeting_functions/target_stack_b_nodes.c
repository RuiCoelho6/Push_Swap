/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_stack_b_nodes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:44:02 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/29 15:26:30 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	init_index_and_median(t_stack_node *stack)
{
	int	i;
	int	median;
	
	i = 0;
	median = ft_stack_len(stack) / 2;
	while(stack)
	{
		stack->index = i;
		if(i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	stack_a_set_targets(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*b_node;
	t_stack_node	*best_match;

	while (stack_a)
	{
		best_match = NULL;
		b_node = stack_b;
		while (b_node)
		{
			if ((!best_match && b_node->content < stack_a->content)
				|| (b_node->content < stack_a->content 
				&& b_node->content > best_match->content))
				best_match = b_node;
			b_node = b_node->next;
		}
		if (best_match == NULL)
			stack_a->target_node = ft_find_max_node(stack_b);
		else
			stack_a->target_node = best_match;
		stack_a = stack_a->next;
	}
}

static void	set_push_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	while (stack_a)
	{
		if(stack_a->above_median)
			stack_a->push_cost = stack_a->index;
		else
			stack_a->push_cost = ft_stack_len(stack_a) - stack_a->index;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		init_index_and_median(stack_b);
		if(stack_b->above_median)
			stack_b->push_cost = stack_b->index;
		else
			stack_b->push_cost = ft_stack_len(stack_b) - stack_b->index;
		stack_b = stack_b->next;
	}
}

void	set_cheapest_node(t_stack_node *stack)
{
	long			cheapest_push_cost;
	t_stack_node	*cheapest_node;
	
	cheapest_push_cost = LONG_MAX;
	while (stack)
	{
		if(stack->push_cost < cheapest_push_cost)
		{
			cheapest_push_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	target_stack_b_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	stack_a_set_targets(stack_a, stack_b);
	set_push_cost(stack_a, stack_b);
	set_cheapest_node(stack_a);
}
