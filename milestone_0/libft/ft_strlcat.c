/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:18:46 by candriam          #+#    #+#             */
/*   Updated: 2024/02/29 14:40:52 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	int		i;

	i = 0;
	dst_len = ft_strlen(dst);
	if (dst_len < size)
	{
		while (src[i] != '\0' && i + dst_len < (size - 1))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		while (src[i] != '\0')
			i++;
	}
	else
	{
		while (src[i] != '\0')
			i++;
		return (i + size);
	}
	return (dst_len + i);
}
