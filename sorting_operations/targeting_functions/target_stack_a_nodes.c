/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_stack_a_nodes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:37:09 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/26 12:42:36 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	stack_b_set_targets(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*a_node;
	t_stack_node	*best_match;

	while(stack_b)
	{
		best_match = NULL;
		a_node = stack_a;
		while(a_node)
		{
			if ((!best_match && a_node->content > stack_b->content) 
				|| (a_node->content > stack_b->content 
				&& a_node->content < best_match->content))
				best_match = a_node;
			a_node = a_node->next;
		}
		if (best_match == NULL)
			stack_b->target_node = ft_find_min_node(stack_a);
		else
			stack_b->target_node = best_match;
		stack_b = stack_b->next;
	}
}

void	target_stack_a_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	init_index_and_median(stack_a);
	init_index_and_median(stack_b);
	stack_b_set_targets(stack_a, stack_b);
}