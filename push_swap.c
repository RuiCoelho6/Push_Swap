/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:33:27 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/29 14:35:15 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**strs;

	stack_a = NULL;
	stack_b = NULL;
	strs = NULL;
	if(ac == 2)
		strs = ft_split(av[1], ' ');
	init_stack_a(&stack_a, strs);
	if (!(ft_stack_sorted(stack_a)))
 	{
		if (ft_stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (ft_stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else if (ft_stack_len(stack_a) > 3)
			ft_sort_stacks(&stack_a, &stack_b);
	}
	while (stack_a)
	{
		ft_printf("%d ", stack_a-> content);
		stack_a = stack_a->next;
	}
	free_stack(&stack_a);
	return (0);
}