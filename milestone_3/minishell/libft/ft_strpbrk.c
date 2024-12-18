/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:20:48 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/03 16:40:34 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	int	i;

	if (!s || !accept)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (accept[i])
		{
			if (*s == accept[i])
				return ((char *)s);
			i++;
		}
		s++;
	}
	return (NULL);
}
