/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:05:43 by candriam          #+#    #+#             */
/*   Updated: 2024/12/13 18:19:21 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\r' || c == '\n' || c == '\f' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

int	ft_len(char **dim)
{
	int	len;

	len = 0;
	while (*dim)
	{
		len++;
		dim++;
	}
	return (len);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_is_digit(*str))
			return (-1);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

void	ft_free_array(char **argv)
{
	int	pos;

	if (!argv)
		return ;
	pos = 0;
	if (argv)
	{
		while (argv[pos])
		{
			free(argv[pos]);
			argv[pos] = NULL;
			pos++;
		}
		free(argv);
		argv = NULL;
	}
}

int	ft_str_equal(const char *str1, const char *str2)
{
	size_t	size;

	if (!str1 || !str2)
		return (0);
	size = ft_strlen(str1);
	if (size != ft_strlen(str2))
		return (0);
	return (ft_strncmp(str1, str2, size) == 0);
}
