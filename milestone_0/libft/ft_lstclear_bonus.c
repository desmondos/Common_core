/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:32:31 by candriam          #+#    #+#             */
/*   Updated: 2024/03/01 10:20:49 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;
	t_list	*tmp;

	now = *lst;
	if (!lst || !del)
		return ;
	while (now)
	{
		tmp = now;
		now = now->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
