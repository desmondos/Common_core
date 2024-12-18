/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:26 by candriam          #+#    #+#             */
/*   Updated: 2024/03/13 09:27:31 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nb);
int	ft_print_unbr(unsigned int nb);
int	ft_print_lowhexa(unsigned int nb);
int	ft_print_uphexa(unsigned int nb);
int	ft_putadress(unsigned long long nb);
int	ft_print_adress(unsigned long long nb);
int	ft_check_in(va_list args, char c);
int	ft_printf(const char *format, ...);

#endif
