/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:37:32 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/29 14:17:24 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	number;
	int		sign;

	number = 0;
	i = 0;
	sign = 1; 
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		number = number * 10 + (str[i++] - '0');
	return (number * sign);
}

t_stack_node	*ft_find_last_node(t_stack_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_append_node(t_stack_node **stack, long number)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if(!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if(!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = number;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **stack_a, char **strs)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while(strs[i] != 0)
	{
		if (error_syntax(strs[i]))
			free_errors(stack_a);
		nbr = ft_atol(strs[i]);
		if (nbr > INT_MAX || nbr < INT_MIN) //Check for overflow
			free_errors(stack_a);
		if (error_duplicate(*stack_a, (int)nbr))
			free_errors(stack_a); 
		ft_append_node(stack_a, ft_atol(strs[i]));
		i++;
	}
}