/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:46:55 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/20 16:17:06 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
/*
int	main(void)
{
    size_t max_size = SIZE_MAX;
    
    printf("%s", (char *)calloc(214736470, 1));
    printf("%s", (char *)ft_calloc(214736470, 1));
    return(0);
}*/