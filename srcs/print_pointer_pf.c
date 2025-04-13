/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:51:37 by theo              #+#    #+#             */
/*   Updated: 2025/04/13 19:16:32 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_pointer_pf(void *ptr)
{
	int		len;
	char	*hex;

	if (!ptr)
		return (write (1, "(nil)", 5));
	hex = conver_base((unsigned long)ptr, HEX_BASE_LOWER);
	if (!hex)
		return (0);
	ft_putstr_fd("0x", 1);
	len = 0;
	while (hex[len])
		write (1, &hex[len++], 1);
	free (hex);
	return (len + 2);
}
