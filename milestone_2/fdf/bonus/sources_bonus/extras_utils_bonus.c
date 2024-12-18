/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:56:49 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:15:20 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	puterror(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (-1);
}

int	is_fdf_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	return (ft_strcmp(&filename[len - 4], ".fdf") == 0);
}

int	ft_isxdigit(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int	ft_htoi(const char *str)
{
	int		value;
	char	digit;

	value = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str && ft_isxdigit(*str))
	{
		digit = *str++;
		if (digit >= '0' && digit <= '9')
			value = value * 16 + (digit - '0');
		else if (digit >= 'a' && digit <= 'f')
			value = value * 16 + (digit - 'a' + 10);
		else if (digit >= 'A' && digit <= 'F')
			value = value * 16 + (digit - 'A' + 10);
		else
			break ;
	}
	return (value);
}
