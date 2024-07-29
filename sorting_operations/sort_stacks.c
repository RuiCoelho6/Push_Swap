/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:18:11 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/29 14:36:44 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	pb(stack_a, stack_b);
}

static void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	prep_a_for_push(stack_a, (*stack_b)->target_node);
	pa(stack_a, stack_b);
}

static void	min_on_top(t_stack_node **stack_a)
{
	while ((*stack_a)->content != ft_find_min_node(*stack_a)->content)
	{
		if (ft_find_min_node(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	ft_sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len_stack_a;

	len_stack_a = ft_stack_len(*stack_a);
	if(len_stack_a-- > 3 && !(ft_stack_sorted(*stack_a)))
		pb(stack_a, stack_b);
	if(len_stack_a-- > 3 && !(ft_stack_sorted(*stack_a)))
		pb(stack_a, stack_b);
	while(len_stack_a-- > 3 && !(ft_stack_sorted(*stack_a)))
	{
		target_stack_b_nodes(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while(*stack_b)
	{
		target_stack_a_nodes(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	init_index_and_median(*stack_a);
	min_on_top(stack_a);
}