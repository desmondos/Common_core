/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:14:38 by candriam          #+#    #+#             */
/*   Updated: 2024/02/24 14:56:37 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little || (big == NULL && !len))
		return ((char *)big);
	while (*(big + i) && i < len)
	{
		j = 0;
		while (*(big + i + j) == *(little + j) && (i + j) < len)
		{
			if (*(little + j + 1) == 0)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
