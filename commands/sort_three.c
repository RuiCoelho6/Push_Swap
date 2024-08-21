/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:03 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/21 13:23:04 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack_node **stack_a) 
{
	t_stack_node	*biggest_node; 

	biggest_node = ft_find_max_node(*stack_a);
	if (biggest_node == *stack_a) 
		ra(stack_a, false); 
	else if ((*stack_a)->next == biggest_node) 
		rra(stack_a, false); 
	if ((*stack_a)->content > (*stack_a)->next->content) 
		sa(stack_a, false); 
}
