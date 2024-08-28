/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_stack_b_nodes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:58 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/27 14:39:48 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index_median(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_targets_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*b_node;
	t_stack_node	*target_node;
	long			best_match;

	while (stack_a)
	{
		best_match = LONG_MIN;
		b_node = stack_b;
		while (b_node)
		{
			if (b_node->content < stack_a->content
				&& b_node->content > best_match)
			{
				best_match = b_node->content;
				target_node = b_node;
			}
			b_node = b_node->next;
		}
		if (best_match == LONG_MIN)
			stack_a->target_node = ft_find_max_node(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	set_a_push_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = ft_stack_len(stack_a);
	stack_b_len = ft_stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = stack_a_len - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += stack_b_len - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest_node(t_stack_node *stack)
{
	long			nbr;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	nbr = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < nbr)
		{
			nbr = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_a_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_index_median(stack_a);
	set_index_median(stack_b);
	set_targets_a(stack_a, stack_b);
	set_a_push_cost(stack_a, stack_b);
	set_cheapest_node(stack_a);
}
