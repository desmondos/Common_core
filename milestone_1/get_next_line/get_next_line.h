/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:42:43 by candriam          #+#    #+#             */
/*   Updated: 2024/03/26 10:51:42 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	ft_cleanlst(t_list **list);
char	*ft_getline(t_list *list);
void	ft_makelst(t_list **list, int fd);
int		ft_is_newline(t_list *list);
void	ft_addback(t_list **list, char *sub);
t_list	*ft_is_lastlst(t_list *list);
void	ft_subcpy(t_list *list, char *sub);
int		ft_newline_len(t_list *list);
void	ft_clean_alloc(t_list **list, t_list *new_list, char *sub);

#endif
