# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 16:26:25 by rpires-c          #+#    #+#              #
#    Updated: 2024/07/25 16:58:40 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SOURCES = push_swap.c init_stack_a.c error_functions.c\
push_swap_stack_utils.c \
push_swap_operations/swap_operations.c \
push_swap_operations/push_operations.c \
push_swap_operations/reverse_rotation_operations.c \
push_swap_operations/rotation_operations.c \
sorting_operations/sort_three.c \
sorting_operations/sort_stacks.c \
sorting_operations/sort_stacks_utils.c \
sorting_operations/targeting_functions/target_stack_a_nodes.c \
sorting_operations/targeting_functions/target_stack_b_nodes.c \
inc/Printf/ft_putstrlen.c inc/Printf/ft_print_pointer.c \
inc/Printf/ft_putchar.c inc/Printf/ft_putnbr_base.c \
inc/Printf/ft_printf.c inc/Printf/libft/ft_isdigit.c\
inc/Printf/libft/ft_split.c inc/Printf/libft/ft_calloc.c \
inc/Printf/libft/ft_bzero.c inc/Printf/libft/ft_strlen.c \

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	cc -g -o push_swap -Wall -Werror -Wall $(SOURCES)

%.o:%.c ft_printf.h
	cc -c $(FLAGS) -o $@ $<  

clean:
	rm -f  $(OBJECT)

fclean: clean
	rm -f $(NAME) 

re: fclean all

exec:
	cc -g -o push_swap -Wall -Werror -Wall $(SOURCES)

.PHONY: all clean fclean re

norm: 
	yes y | python3 -m c_formatter_42 -c $(SOURCES)