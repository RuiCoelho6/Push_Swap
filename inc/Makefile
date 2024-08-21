# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 13:23:32 by rpires-c          #+#    #+#              #
#    Updated: 2024/08/21 13:23:33 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

FLAGS			= -Wall -Wextra -Werror -I inc/
RM				= rm -f
AR				= ar rcs

SRCS =	libft/ft_isdigit.c \
		libft/ft_strlen.c \
		Printf/ft_printf.c  \
		Printf/ft_print_pointer.c  \
		Printf/ft_putchar.c  \
		Printf/ft_putnbr_base.c  \
		Printf/ft_putstrlen.c \

OBJ 			= $(SRCS:.c=.o)

all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(AR) $(NAME) $(OBJ)

%.o: %.c
				@cc $(FLAGS) -c $< -o $@

clean:
				@$(RM) $(OBJ)
				@$(RM) .cache_exists

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re

