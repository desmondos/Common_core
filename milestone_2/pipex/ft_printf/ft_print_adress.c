/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:21:25 by candriam          #+#    #+#             */
/*   Updated: 2024/07/17 08:56:39 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putadress(unsigned long long nb)
{
	char	*base;
	int		result;

	base = "0123456789abcdef";
	result = 0;
	if (nb >= 16)
	{
		result += ft_putadress(nb / 16);
		result += ft_putadress(nb % 16);
	}
	else
		result += ft_print_char(base[nb % 16]);
	return (result);
}

int	ft_print_adress(unsigned long long nb)
{
	char	*base;
	int		result;

	base = "0123456789abcdef";
	result = 0;
	if (nb == 0)
	{
		result = write(1, "(nil)", 5);
		return (result);
	}
	else
	{
		if (nb < 16)
		{
			result = ft_print_str("0x");
			result += ft_print_char(base[nb % 16]);
		}
		else
		{
			result = ft_print_str("0x");
			result += ft_putadress(nb / 16);
			result += ft_putadress(nb % 16);
		}
	}
	return (result);
}
