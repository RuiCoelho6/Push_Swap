/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:49:58 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/25 16:57:18 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	return (0);
}

int	error_duplicate(t_stack_node *stack_a, int n)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->content == n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		node->content = 0;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **stack_a)
{
	free_stack(stack_a);
	ft_printf("Error\n");
	exit(1);
}