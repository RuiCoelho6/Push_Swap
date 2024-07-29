/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:41:03 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/25 11:31:01 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack_node	*ft_find_min_node(t_stack_node *stack)
{
	long			min_content;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_content = LONG_MAX;
	while (stack)
	{
		if (stack->content < min_content)
		{
			min_content = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*ft_find_max_node(t_stack_node *stack)
{
	long			max; 
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

bool	ft_stack_sorted(t_stack_node *stack)
{
	while(stack->next)
	{
		if(stack->content > stack->next->content)
			return (false);
		stack = stack -> next;
	}
	return(true);
}

int	ft_stack_len(t_stack_node *stack)
{
	int	node_counter;

	node_counter = 0;
	while(stack)
	{
		node_counter++;
		stack = stack->next;
	}
	return (node_counter);
}
