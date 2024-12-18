/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:29:00 by candriam          #+#    #+#             */
/*   Updated: 2024/07/27 17:14:13 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_count_words(char const *s, char delim)
{
	int	words;
	int	in_word;

	words = 0;
	while (*s)
	{
		in_word = 0;
		while (*s && (*s == delim))
			s++;
		while (*s && (*s != delim))
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

static	char	*ft_next_word(char const *s, char delim)
{
	static int	pos = 0;
	char		*next_word;
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (s[pos] == delim)
		pos++;
	while (s[pos + len] && (s[pos + len] != delim))
		len++;
	next_word = malloc(len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (s[pos] && s[pos] != delim)
		next_word[i++] = s[pos++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char const *s, char c)
{
	char	**wordv;
	int		words;
	int		i;

	i = 0;
	words = ft_count_words(s, c);
	if (!words)
		exit(1);
	wordv = malloc(sizeof(char *) * (words + 2));
	if (wordv == NULL)
		return (NULL);
	while (words-- >= 0)
	{
		if (i == 0)
		{
			wordv[i] = malloc(sizeof(char));
			if (!wordv[i])
				return (NULL);
			wordv[i++][0] = '\0';
			continue ;
		}
		wordv[i++] = ft_next_word(s, c);
	}
	wordv[i] = NULL;
	return (wordv);
}
