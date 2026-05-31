/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:39:38 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/23 16:26:50 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_array(char **array, size_t word)
{
	while (word > 0)
	{
		free(array[--word]);
	}
	free(array);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	index;

	words = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			words++;
			while (s[index] && s[index] != c)
				index++;
		}
		else
			index++;
	}
	return (words);
}

static int	malloc_array(char ***result, char const *s, char c)
{
	size_t	words;

	words = count_words(s, c);
	*result = malloc((words + 1) * sizeof(char *));
	if (!*result)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		index;
	size_t		index2;
	size_t		word_len;

	if (!s || !malloc_array(&result, s, c))
		return (NULL);
	index = 0;
	index2 = 0;
	while (index2 < count_words(s, c))
	{
		while (s[index] == c)
			index++;
		word_len = 0;
		while (s[index + word_len] && s[index + word_len] != c)
			word_len++;
		result[index2++] = ft_substr(s, index, word_len);
		if (!result[index2 - 1])
			return (free_array(result, index2 - 1), NULL);
		index += word_len;
	}
	result[index2] = NULL;
	return (result);
}
