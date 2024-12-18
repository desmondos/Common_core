/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:30:44 by candriam          #+#    #+#             */
/*   Updated: 2024/07/19 13:54:56 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_num_len(int num)
{
	size_t	pos;

	pos = 0;
	if (num <= 0)
		pos++;
	while (num != '\0')
	{
		num /= 10;
		pos++;
	}
	return (pos);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		pos;
	int		len;

	len = ft_num_len(n);
	pos = len - 1;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n != '\0')
	{
		if (n < 0)
			result[pos--] = (~(n % 10) + 1) + '0';
		else
			result[pos--] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>

// Your ft_itoa function here

int main() {
    int number = 2147483647; // Example number to convert

    // Convert the integer to a string
    char *str = ft_itoa(number);

    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    printf("Integer: %d\nString: %s\n", number, str);

    // Don't forget to free the allocated memory
    free(str);

    return 0; // Indicates success
}*/
