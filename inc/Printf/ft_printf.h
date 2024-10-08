/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:40:57 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/20 17:44:20 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <aio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_pointer(unsigned long int decimal);
int	ft_putnbr_base(long int nbr, char *base, int lock_neg);
int	ft_putchar(char c);
int	ft_putstrlen(char *s);

#endif
