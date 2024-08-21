/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:22:53 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/21 13:22:54 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack_node **stack) 
{
	t_stack_node	*last; 

	if (!*stack || !(*stack)->next) 
		return ;
	last = ft_find_last_node(*stack);
	last->prev->next = NULL; 
	last->next = *stack; 
	last->prev = NULL; 
	*stack = last;  
	last->next->prev = last; 
}

void	rra(t_stack_node **stack_a, bool print) 
{
	rev_rotate(stack_a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b, bool print) 
{
	rev_rotate(stack_b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print) 
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!print)
		ft_printf("rrr\n");
}