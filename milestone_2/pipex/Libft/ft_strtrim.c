/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:58:24 by candriam          #+#    #+#             */
/*   Updated: 2024/07/19 13:58:43 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*str;

	first = 0;
	last = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[first]) && s1[first])
		first++;
	if (first > last)
		return (ft_strdup(s1 + last + 1));
	while (ft_strchr(set, s1[last]) && s1[last])
		last--;
	str = malloc(last - first + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[first], last - first + 2);
	return (str);
}
