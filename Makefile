# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 13:24:01 by rpires-c          #+#    #+#              #
#    Updated: 2024/08/21 13:24:02 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./inc/libft.a
INC = -I ./inc/

FLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS =	commands/push.c \
		commands/rev_rotate.c \
		commands/rotate.c \
		commands/sort_stacks.c \
		commands/sort_three.c \
		commands/swap.c \
		main/error_handler.c \
		main/target_stack_b_nodes.c \
		main/target_stack_a_nodes.c \
		main/push_swap.c \
		main/push_split.c \
		main/stack_init_utils.c \
		main/stack_utils.c

all:	$(NAME)

OBJ = $(SRCS:.c=.o)

$(LIBFT):
	@make -C ./inc

$(NAME):	$(OBJ) $(LIBFT)
	@cc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	@cc $(FLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C ./inc

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C ./inc

re:	fclean all

.PHONY:	all clean fclean re
