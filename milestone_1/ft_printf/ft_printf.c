/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:32:23 by candriam          #+#    #+#             */
/*   Updated: 2024/03/13 09:25:49 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, format);
	result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			result += ft_check_in(args, format[i]);
		}
		else
			result += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (result);
}
