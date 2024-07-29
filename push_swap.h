/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:26:53 by rpires-c          #+#    #+#             */
/*   Updated: 2024/07/29 14:32:26 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdbool.h>
# include "inc/Printf/ft_printf.h"

typedef struct s_stack_node
{
	int		index;
	long		content;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
} t_stack_node;

void	init_stack_a(t_stack_node **stack_a, char **strs);
long	ft_atol(char *str);
bool	ft_stack_sorted(t_stack_node *stack);
int	ft_stack_len(t_stack_node *stack);
void	sa(t_stack_node **stack_a);
void	sb(t_stack_node **stack_b);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
void	ra(t_stack_node **stack_a);
void	rb(t_stack_node **stack_b);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
void	rra(t_stack_node **stack_a);
void	rrb(t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pb(t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_three(t_stack_node **stack_a);
t_stack_node	*ft_find_min_node(t_stack_node *stack);
t_stack_node	*ft_find_max_node(t_stack_node *stack);
t_stack_node	*ft_find_last_node(t_stack_node *stack);
void	init_index_and_median(t_stack_node *stack);
void	set_cheapest_node(t_stack_node *stack);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node);
void	rev_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node);
void	prep_a_for_push(t_stack_node **stack_a, t_stack_node *top_node);
void	prep_b_for_push(t_stack_node **stack_b, t_stack_node *top_node);
void	ft_sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b);
void	target_stack_b_nodes(t_stack_node *stack_a, t_stack_node *stack_b);
void	target_stack_a_nodes(t_stack_node *stack_a, t_stack_node *stack_b);
int	error_syntax(char *str_n);
int	error_duplicate(t_stack_node *stack_a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **stack_a);
#endif