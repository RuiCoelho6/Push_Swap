/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:39 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/27 15:40:14 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	duplicate_error(t_stack_node *stack_a, int nbr)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->content == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current_node;

	if (!stack)
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp = current_node->next;
		current_node->content = 0;
		free(current_node);
		current_node = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **stack_a, char **argv, bool free_argv)
{
	if (stack_a)
		free_stack(stack_a);
	if (free_argv && argv)
		free_array(argv);
	ft_printf("Error\n");
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
