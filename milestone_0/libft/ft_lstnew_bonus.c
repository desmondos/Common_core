/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:38:41 by candriam          #+#    #+#             */
/*   Updated: 2024/02/29 11:07:18 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*now;

	now = malloc(sizeof(t_list));
	if (!now)
		return (NULL);
	now->content = content;
	now->next = NULL;
	return (now);
}
