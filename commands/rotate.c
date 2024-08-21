/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:22:57 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/21 13:22:58 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_node **stack) 
{
	t_stack_node	*last_node; 

	if (!*stack || !(*stack)->next) 
		return ;
	last_node = ft_find_last_node(*stack); 
	last_node->next = *stack; 
	*stack = (*stack)->next; 
	(*stack)->prev = NULL; 
	last_node->next->prev = last_node; 
	last_node->next->next = NULL; 
}		

void	ra(t_stack_node **stack_a, bool print) 
{
	rotate(stack_a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b, bool print) 
{
	rotate(stack_b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print) 
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_printf("rr\n");
}