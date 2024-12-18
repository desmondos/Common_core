/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:49:39 by candriam          #+#    #+#             */
/*   Updated: 2024/12/13 17:51:25 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "../includes/structure.h"

int		is_redirect_char(char c);
int		skip_spaces(char *input, int i);
int		is_blank(char *input);
int		handle_redirect(char *input, int i);
int		empty_input(char *input);
int		unclose_quotes(char *str);
int		is_invalid_input(char *input);
int		pipe_start_input(char *input);
char	*get_pipes(char *str);
int		invalid_token(char c);
int		invalid_redirect(char *input);

int		do_ignore(char *input);
void	update_input(char **input, char *var_value, char *second_part);
void	null_input(char **input, t_env **env);
int		input_error(char *input, t_env *env, int *status);

int		ft_is_alpha(char c);
int		is_under_score(char c);
int		ft_is_digit(char c);
int		ft_is_alnum(char c);
int		is_var_name(char c);

#endif
