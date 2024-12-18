/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:36:39 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/16 15:59:12 by frajaona         ###   ########.fr       */
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

typedef enum e_state
{
	UP,
	READ,
	RESET
}			t_state;

#endif
