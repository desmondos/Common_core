/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:13:55 by candriam          #+#    #+#             */
/*   Updated: 2024/07/19 13:58:51 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	new_len;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	new_len = (s_len - start);
	if (!s)
		return (NULL);
	if (start >= (unsigned int)s_len)
		return (ft_strdup(""));
	if (new_len > len)
		new_len = len;
	new = malloc(new_len + 1);
	if (new == NULL)
		return (NULL);
	while (s[start] && i < new_len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
