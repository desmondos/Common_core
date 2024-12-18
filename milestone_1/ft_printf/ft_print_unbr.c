/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:10:54 by candriam          #+#    #+#             */
/*   Updated: 2024/03/13 09:26:34 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_unbr(unsigned int nb)
{
	unsigned int	result;

	result = 0;
	if (nb > 9)
	{
		result += ft_print_unbr(nb / 10);
		result += ft_print_unbr(nb % 10);
	}
	else
		result += ft_print_char(nb + 48);
	return (result);
}
