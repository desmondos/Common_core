/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:49:55 by candriam          #+#    #+#             */
/*   Updated: 2024/07/17 08:57:07 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_print_nbr(int nb)
{
	int	result;

	result = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		result += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		result += ft_print_nbr(nb / 10);
		result += ft_print_nbr(nb % 10);
	}
	else
		result += ft_print_char(nb + 48);
	return (result);
}
