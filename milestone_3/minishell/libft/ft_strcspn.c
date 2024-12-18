/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:42:04 by frajaona          #+#    #+#             */
/*   Updated: 2024/08/07 11:28:52 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	index_s;
	int	index_rej;

	index_s = 0;
	while (s[index_s] != '\0')
	{
		index_rej = 0;
		while (reject[index_rej] != '\0')
		{
			if (s[index_s] == reject[index_rej])
				return (index_s);
			index_rej++;
		}
		index_s++;
	}
	return (index_s);
}
