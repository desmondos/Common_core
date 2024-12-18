/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:21:35 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/03 16:40:36 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token = NULL;
	char		*end_token;

	if (str == NULL)
		str = next_token;
	if (str == NULL)
		return (NULL);
	str += ft_strspn(str, delim);
	if (*str == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	end_token = ft_strpbrk(str, delim);
	if (end_token != NULL)
	{
		*end_token = '\0';
		next_token = end_token + 1;
	}
	else
		next_token = NULL;
	return (str);
}
