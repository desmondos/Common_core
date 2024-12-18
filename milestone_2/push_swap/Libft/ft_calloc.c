/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:16:54 by candriam          #+#    #+#             */
/*   Updated: 2024/07/15 17:47:44 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mems;
	void	*ptr;

	mems = (nmemb * size);
	if (size && (mems / size) != nmemb)
		return (NULL);
	ptr = malloc(mems);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, mems);
	return (ptr);
}
