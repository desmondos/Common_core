/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:29:00 by candriam          #+#    #+#             */
/*   Updated: 2024/09/20 15:52:01 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	size_t	ft_count_words(char const *s, char delim)
{
	size_t	words;
	int		in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == delim)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			words++;
		}
		s++;
	}
	return (words);
}

static	int	ft_alloc(char **wordv, int pos, size_t len)
{
	wordv[pos] = malloc(len);
	if (wordv[pos] == NULL)
	{
		while (pos--)
			free(wordv[pos]);
		free(wordv);
		return (1);
	}
	return (0);
}

static void	ft_fill_words(char **wordv, char const *s, char delim)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delim)
			s++;
		while (s[len] && s[len] != delim)
			len++;
		if (len > 0)
		{
			if (ft_alloc(wordv, i, len + 1))
				return ;
			ft_memcpy(wordv[i], s, len);
			wordv[i][len] = '\0';
			i++;
		}
		s += len;
	}
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
	ft_fill_words(wordv, s, c);
	return (wordv);
}
