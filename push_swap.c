/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:45 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/28 14:12:51 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorter(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_stack_len(*stack_a) == 2)
		sa(stack_a, false);
	else if (ft_stack_len(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_stacks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	bool			free_argv;

	free_argv = false;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		free_errors(&stack_a, argv, free_argv);
	else if (argc == 2)
	{
		argv = push_split(argv[1], ' ');
		free_argv = true;
	}
	init_stack(&stack_a, argv, free_argv);
	if (!ft_stack_sorted(stack_a))
		choose_sorter(&stack_a, &stack_b);
	free_stack(&stack_a);
	if (free_argv)
		free_array(argv);
	return (0);
}
