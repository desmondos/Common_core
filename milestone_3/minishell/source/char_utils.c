/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:32:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 14:59:14 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_')
		return (1);
	else
		return (0);
}

int	is_under_score(char c)
{
	if (c == '_')
		return (1);
	else
		return (0);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_alnum(char c)
{
	if (ft_is_alpha(c) == 1 || ft_is_digit(c) == 1)
		return (1);
	else
		return (0);
}

int	is_var_name(char c)
{
	if (ft_is_alnum(c) == 1)
		return (1);
	else if (is_under_score(c) == 1)
		return (1);
	else
		return (0);
}
