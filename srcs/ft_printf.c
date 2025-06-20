/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:11:54 by theo              #+#    #+#             */
/*   Updated: 2025/04/11 20:01:40 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	formats_print(va_list *args, const char specifier)
{
	if (specifier == 'c')
		return (ft_putchar_lf(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_putstr_pf(va_arg(*args, char *)));
	else if (specifier == 'p')
		return (print_pointer_pf(va_arg(*args, void *)));
	else if (specifier == 'u')
		return (print_unsigned_pf(va_arg(*args, unsigned int)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_signed_pf(va_arg(*args, int)));
	else if (specifier == 'x')
		return (print_hex_pf(va_arg(*args, unsigned int), 0));
	else if (specifier == 'X')
		return (print_hex_pf(va_arg(*args, unsigned int), 1));
	else if (specifier == '%')
		return (print_percent_pf());
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			count += formats_print(&args, *(s + 1));
			s++;
		}
		else
			count += ft_putchar_lf(*s);
		s++;
	}
	va_end(args);
	return (count);
}
