/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:05 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/24 12:08:25 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack_node **first_node)
{
	if (!*first_node || !(*first_node)->next)
		return ;
	*first_node = (*first_node)->next;
	(*first_node)->prev->prev = *first_node;
	(*first_node)->prev->next = (*first_node)->next;
	if ((*first_node)->next)
		(*first_node)->next->prev = (*first_node)->prev;
	(*first_node)->next = (*first_node)->prev;
	(*first_node)->prev = NULL;
}

void	sa(t_stack_node	**stack_a, bool print)
{
	swap(stack_a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **stack_b, bool print)
{
	swap(stack_b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		ft_printf("ss\n");
}
