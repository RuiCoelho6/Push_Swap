/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:50 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/21 13:23:51 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stack_len(t_stack_node *stack) 
{
	int	count; 

	if (!stack) 
		return (0);
	count = 0;
	while (stack) 
	{
		stack = stack->next; 
		count++;
	}
	return (count);
}

t_stack_node	*ft_find_last_node(t_stack_node *stack) 
{
	if (!stack)
		return (NULL);
	while (stack->next) 
		stack = stack->next;
	return (stack);
}

bool	ft_stack_sorted(t_stack_node *stack) 
{
	if (!stack)
		return (1);
	while (stack->next) 
	{
		if (stack->content > stack->next->content) 
			return (false);
		stack = stack->next; 
	}
	return (true);
}

t_stack_node	*ft_find_min_node(t_stack_node *stack) 
{
	long			min; 
	t_stack_node	*min_node; 

	if (!stack)
		return (NULL);
	min = LONG_MAX; 
	while (stack) 
	{
		if (stack->content < min) 
		{
			min = stack->content; 
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
