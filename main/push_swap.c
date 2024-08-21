/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:45 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/21 13:23:46 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv) 
{
	t_stack_node	*stack_a; 
	t_stack_node	*stack_b; 

	stack_a = NULL; 
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) 
		return (1);
	else if (argc == 2) 
		argv = push_split(argv[1], ' '); 
	init_stack(&stack_a, argv + 1); 
	if (!ft_stack_sorted(stack_a)) 
	{
		if (ft_stack_len(stack_a) == 2) 
			sa(&stack_a, false);
		else if (ft_stack_len(stack_a) == 3) 
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b); 
	}
	free_stack(&stack_a); 
	return (0);
}
