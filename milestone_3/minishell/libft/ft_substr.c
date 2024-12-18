/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:13:55 by candriam          #+#    #+#             */
/*   Updated: 2024/07/15 17:56:20 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*new_start;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	new = malloc(sizeof(*s) * len + 1);
	if (!new)
		return (NULL);
	while (*s && start--)
		s++;
	new_start = new;
	while (*s && len)
	{
		*new = *s;
		new++;
		s++;
		len--;
	}
	*new = '\0';
	return (new_start);
}
