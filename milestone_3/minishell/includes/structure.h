/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:36:39 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/18 16:42:37 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# define ENV_SIZE 4096

typedef struct s_env
{
	int				statu;
	char			*data;
	char			*dir;
	char			*pwd;
	char			*old;
	char			cwd[ENV_SIZE];
	struct s_env	*next;
}				t_env;

typedef struct s_heredoc
{
	t_env			*env;
	char			*delim;
	char			*read_line;
	int				tmp_fd;
}				t_heredoc;

typedef enum e_state
{
	UP,
	READ,
	RESET
}			t_state;

#endif
