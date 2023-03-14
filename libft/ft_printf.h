/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:28:38 by migmarti          #+#    #+#             */
/*   Updated: 2022/12/06 11:30:00 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_print_char(char c);
int	ft_print_string(char *s);
int	ft_print_numb(long nb);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_hexadecimal(unsigned long nb, char c);
int	ft_print_pointer(unsigned long nb);
int	ft_check_specifier(char c, va_list args);
int	ft_printf(const char *s, ...);

#endif
