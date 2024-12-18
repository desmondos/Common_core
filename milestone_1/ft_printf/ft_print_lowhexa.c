/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowhexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:18:30 by candriam          #+#    #+#             */
/*   Updated: 2024/03/13 09:26:02 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_lowhexa(unsigned int nb)
{
	unsigned int	result;
	char			*base;

	base = "0123456789abcdef";
	result = 0;
	if (nb >= 16)
	{
		result += ft_print_lowhexa(nb / 16);
		result += ft_print_lowhexa(nb % 16);
	}
	else
		result += ft_print_char(base[nb % 16]);
	return (result);
}
