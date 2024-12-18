/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:29:00 by candriam          #+#    #+#             */
/*   Updated: 2024/07/19 13:56:47 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	size_t	ft_count_words(char const *s, char delim)
{
	size_t	words;
	int		in_word;

	words = 0;
	while (*s)
	{
		in_word = 0;
		while (*s && *s == delim)
			s++;
		while (*s && *s != delim)
		{
			if (!in_word)
			{
				words++;
				in_word = 1;
			}
			s++;
		}
	}
	return (words);
}

static	int	ft_alloc(char **wordv, int pos, size_t len)
{
	int	i;

	i = 0;
	wordv[pos] = malloc(len);
	if (wordv[pos] == NULL)
	{
		while (i < pos)
			free(wordv[i++]);
		free(wordv);
		return (1);
	}
	return (0);
}

static	char	ft_fill_words(char **wordv, char const *s, char delim)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == delim)
			s++;
		while (*s && *s != delim)
		{
			s++;
			len++;
		}
		if (len)
		{
			if (ft_alloc(wordv, i, len + 1))
				return (1);
			ft_strlcpy(wordv[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**wordv;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	wordv = malloc(sizeof(char *) * (words + 1));
	if (wordv == NULL)
		return (NULL);
	wordv[words] = NULL;
	if (ft_fill_words(wordv, s, c))
		return (NULL);
	return (wordv);
}
