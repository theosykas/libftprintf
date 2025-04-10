/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:11:54 by theo              #+#    #+#             */
/*   Updated: 2025/04/10 19:07:35 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	formats_print(va_list args, const char specifier)
{
	if (specifier == 'c')
		return (ft_putchar_lf(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (specifier == 'p')
		return (print_pointer_pf(va_arg(args, void *)));
	else if (specifier == 'u')
		return (print_unsigned_pf(va_arg(args, unsigned int)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_signed_pf(va_arg(args, int)));
	else if (specifier == 'x')
		return (print_hex_pf(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (print_hex_pf(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (print_percent_pf());
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			count += formats_print(args, s[i + 1]);
			i++;
		}
		else
			count += ft_putchar_lf(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
