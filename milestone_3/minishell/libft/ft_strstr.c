/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/11/23 09:21:17 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *input, const char *subchr)
{
	const char	*in;
	const char	*sub;

	if (!*subchr)
		return ((char *)input);
	while (*input)
	{
		in = input;
		sub = subchr;
		while (*in && *sub && (*in == *sub))
		{
			in++;
			sub++;
		}
		if (!*sub)
			return ((char *)input);
		input++;
	}
	return (NULL);
}
