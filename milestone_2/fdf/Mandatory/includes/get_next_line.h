/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:42:43 by candriam          #+#    #+#             */
/*   Updated: 2024/07/14 11:21:14 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	char			*data;
	struct s_data	*next;
}				t_data;

char	*get_next_line(int fd);
void	ft_cleanlst(t_data **list);
char	*ft_getline(t_data *list);
void	ft_makelst(t_data **list, int fd);
int		ft_is_newline(t_data *list);
void	ft_addback(t_data **list, char *sub);
t_data	*ft_is_lastlst(t_data *list);
void	ft_subcpy(t_data *list, char *sub);
int		ft_newline_len(t_data *list);
void	ft_clean_alloc(t_data **list, t_data *new_list, char *sub);

#endif
