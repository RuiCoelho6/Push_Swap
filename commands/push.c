/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:22:50 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/24 12:10:04 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **stack_b, t_stack_node **stack_a, bool print)
{
	push(stack_b, stack_a);
	if (!print)
		ft_printf("pb\n");
}
