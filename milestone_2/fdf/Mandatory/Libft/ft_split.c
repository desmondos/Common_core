/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:29:00 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 23:34:02 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static int	count_words(const char *str, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delimiter && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == delimiter)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

static char	**fill_word(t_split to, const char *s, char c)
{
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			to.word_len = 0;
			while (s[to.word_len] && s[to.word_len] != c)
				to.word_len++;
			to.result[to.i] = (char *)malloc(sizeof(char) * (to.word_len + 1));
			if (!to.result[to.i])
			{
				while (to.i > 0)
					free(to.result[--to.i]);
				free(to.result);
				return (NULL);
			}
			ft_strncpy(to.result[to.i], s, to.word_len);
			to.result[to.i][to.word_len] = '\0';
			to.i++;
			s += to.word_len;
		}
	}
	to.result[to.i] = NULL;
	return (to.result);
}

char	**ft_split(const char *s, char c)
{
	t_split	to;

	to.i = 0;
	to.word_count = count_words(s, c);
	to.result = (char **)malloc(sizeof(char *) * (to.word_count + 1));
	if (!to.result)
		return (NULL);
	if (!fill_word(to, s, c))
		return (NULL);
	return (to.result);
}
