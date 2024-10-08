/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:48 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/28 14:09:02 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static void	ft_append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->content = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_stack_node **stack_a, char **argv, bool free_argv)
{
	long	nbr;
	int		i;

	i = 1;
	if (argv == NULL)
		free_errors(stack_a, argv, free_argv);
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_errors(stack_a, argv, free_argv);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(stack_a, argv, free_argv);
		if (duplicate_error(*stack_a, (int)nbr))
			free_errors(stack_a, argv, free_argv);
		ft_append_node(stack_a, (int)nbr);
		i++;
	}
}

void	prep_a_for_push(t_stack_node **stack, t_stack_node *top_node)
{
	while (*stack != top_node)
	{
		if (top_node->above_median)
			ra(stack, false);
		else
			rra(stack, false);
	}
}

void	prep_b_for_push(t_stack_node **stack, t_stack_node *top_node)
{
	while (*stack != top_node)
	{
		if (top_node->above_median)
			rb(stack, false);
		else
			rrb(stack, false);
	}
}
