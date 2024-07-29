/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:15:37 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/29 14:30:45 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*node_to_push;
	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->next->prev = node_to_push;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a); 
	ft_printf("pa\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}