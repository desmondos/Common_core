/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:47:40 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:45:34 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structure.h"
# include <stdbool.h>

int		ft_isspace(char c);
int		ft_len(char **dim);
long	ft_atol(const char *str);
void	ft_free_array(char **argv);
int		ft_str_equal(const char *str1, const char *str2);

void	ft_print_error(char *command, char *str);
void	ft_printvar_error(char *command, char *str);
void	ft_print_perror(char *command, char *str);
void	exit_error(char *command, char *str, int status);
int		syn_error(char *token);

int		is_valid_varname(char *name);
char	*skip_single_quotes(char *input);
char	*handle_double_quotes(char *input);
char	*var_pos(char *input);

#endif
