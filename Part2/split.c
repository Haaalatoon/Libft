/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:04:22 by hrhilane          #+#    #+#             */
/*   Updated: 2024/11/15 22:10:51 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				++s;
		}
	}
	return (count);
}

size_t	*count_lengths(char const *s, char c)
{
	size_t	len;
	size_t	word_count;
	size_t	*len_word;
	size_t	*ptr;

	word_count = count_words(s, c);
	len_word = (size_t *)malloc(word_count * sizeof(size_t));
	if (!len_word)
		return (NULL);
	ptr = len_word;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (*s && *s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				++s;
				++len;
			}
			*len_word = len;
			++len_word;
		}
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	*lengths;
	char	**split;
	int		i;
	int		j;

	count = count_words(s, c);
	lengths = count_lengths(s, c);
	if (!lengths)
		return (NULL);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
	{
		free(lengths);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		split[i] = (char *)malloc((lengths[i] + 1) * sizeof(char));
		if (!split[i])
		{
			j = 0;
			while (j < i)
			{
				free(split[j]);
				j++;
			}
			free(split);
			free(lengths);
			return (NULL);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < count)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			j = 0;
			while (*s && *s != c)
				split[i][j++] = *s++;
			split[i][j] = '\0';
			i++;
		}
	}
	split[count] = NULL;
	free(lengths);
	return (split);
}
