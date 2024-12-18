/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:01:53 by candriam          #+#    #+#             */
/*   Updated: 2024/07/17 08:56:29 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_check_in(va_list args, char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = ft_print_char(va_arg(args, int));
	else if (c == 's')
		result = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		result += ft_print_adress(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		result = ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		result = ft_print_unbr(va_arg(args, unsigned int));
	else if (c == 'x')
		result = ft_print_lowhexa(va_arg(args, unsigned int));
	else if (c == 'X')
		result = ft_print_uphexa(va_arg(args, unsigned int));
	else if (c == '%')
		return (ft_print_char('%'));
	else
		result += write(1, &c, 1);
	return (result);
}
