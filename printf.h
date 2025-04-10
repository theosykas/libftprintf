/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:37:53 by theo              #+#    #+#             */
/*   Updated: 2025/04/10 16:05:33 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

int			ft_printf(const char *s, ...);

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *source);
char		*convert_base(unsigned int n, const char *base);

int			formats_print(va_list args, const char specifier);
int			ft_putchar_lf(int c);
int			ft_putstr_pf(char *str);
int			print_pointer_pf(void *ptr);
int			print_signed_pf(int n);
int			print_unsigned_pf(unsigned int n);
int			print_hex_pf(unsigned int n, int uppercase);
int			print_percent_pf(void);

#endif