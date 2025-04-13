/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:37:53 by theo              #+#    #+#             */
/*   Updated: 2025/04/13 19:05:32 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

int			ft_printf(const char *s, ...);

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *source);
char		*conver_base(unsigned long n, const char *base);

int			formats_print(va_list *args, const char specifier);
int			ft_putchar_lf(int c);
int			ft_putstr_pf(char *str);
int			print_pointer_pf(void *ptr);
int			print_signed_pf(int n);
int			print_unsigned_pf(unsigned int n);
int			print_hex_pf(unsigned int n, int uppercase);
int			print_percent_pf(void);

#endif