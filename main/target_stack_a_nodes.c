/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_stack_a_nodes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:53 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/21 13:23:54 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_targets_b(t_stack_node *stack_a, t_stack_node *stack_b) 
{
	t_stack_node	*a_node; 
	t_stack_node	*target_node; 
	long			best_match; 

	while (stack_b)
	{
		best_match = LONG_MAX; 
		a_node = stack_a; 
		while (a_node) 
		{
			if (a_node->content > stack_b->content 
				&& a_node->content < best_match) 
			{
				best_match = a_node->content; 
				target_node = a_node; 
			}
			a_node = a_node->next; 
		}
		if (best_match == LONG_MAX) 
			stack_b->target_node = ft_find_min_node(stack_a); 
		else
			stack_b->target_node = target_node; 
		stack_b = stack_b->next; 
	}
}

void	init_b_nodes(t_stack_node *stack_a, t_stack_node *stack_b) 
{
	set_index_median(stack_a);
	set_index_median(stack_b);
	set_targets_b(stack_a, stack_b);
}