/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:04 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/24 12:13:11 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> 
# include <limits.h> 
# include "inc/libft/libft.h"
# include "inc/Printf/ft_printf.h"

typedef struct s_stack_node
{
	int					content;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			min_on_top(t_stack_node **stack_a);
int				syntax_error(char *str_n);
int				duplicate_error(t_stack_node *stack_a, int nbr);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **stack_a);
void			init_stack(t_stack_node **stack_a, char **argv);
char			**push_split(char *s, char c);
void			init_a_nodes(t_stack_node *stack_a, t_stack_node *stack_b);
void			init_b_nodes(t_stack_node *a, t_stack_node *b);
void			set_index_median(t_stack_node *stack);
void			set_cheapest_node(t_stack_node *stack);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
void			prep_a_for_push(t_stack_node **stack, t_stack_node *top_node);
void			prep_b_for_push(t_stack_node **stack, t_stack_node *top_node);
int				ft_stack_len(t_stack_node *stack);
t_stack_node	*ft_find_last_node(t_stack_node *stack);
bool			ft_stack_sorted(t_stack_node *stack);
t_stack_node	*ft_find_min_node(t_stack_node *stack);
t_stack_node	*ft_find_max_node(t_stack_node *stack);
void			sa(t_stack_node **stack_a, bool print);
void			sb(t_stack_node **stack_b, bool print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			ra(t_stack_node **stack_a, bool print);
void			rb(t_stack_node **stack_b, bool print);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			rra(t_stack_node **stack_a, bool print);
void			rrb(t_stack_node **stack_b, bool print);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			pb(t_stack_node **stack_b, t_stack_node **stack_a, bool print);
void			sort_three(t_stack_node **stack_a);
void			sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b);
#endif
