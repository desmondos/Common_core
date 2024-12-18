/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:26:13 by candriam          #+#    #+#             */
/*   Updated: 2024/02/24 14:58:04 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	t_len;
	size_t	i;

	i = 0;
	t_len = (ft_strlen(s1) + ft_strlen(s2));
	s = malloc(t_len + 1);
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	s[t_len] = '\0';
	return (s);
}
