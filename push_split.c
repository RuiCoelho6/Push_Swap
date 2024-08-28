/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:23:42 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/27 14:39:28 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[*cursor] == c)
		(*cursor)++;
	while (str[*cursor + len] != c && str[*cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (str[*cursor] != c && str[*cursor])
		next_word[i++] = str[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

int	put_null_result_array(char ***result_array)
{
	(*result_array)[0] = malloc(sizeof(char));
	if (!(*result_array)[0])
	{
		free_array(*result_array);
		return (-1);
	}
	(*result_array)[0][0] = '\0';
	return (0);
}

int	put_next_word_in_array(char **result_array,
							char *str,
							char c,
							int *cursor)
{
	(*result_array) = get_next_word(str, c, cursor);
	if (!(*result_array))
	{
		free(*result_array);
		return (0);
	}
	return (1);
}

char	**push_split(char *str, char c)
{
	int		words_count;
	char	**result_array;
	int		i;
	int		cursor;

	i = 0;
	cursor = 0;
	words_count = count_words(str, c);
	if (words_count == 0)
		return (NULL);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array || put_null_result_array(&result_array) == -1)
		return (NULL);
	i++;
	while (i <= words_count)
	{
		if (!(put_next_word_in_array(&result_array[i], str, c, &cursor)))
			return (NULL);
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}
