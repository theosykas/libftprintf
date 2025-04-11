/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:51:37 by theo              #+#    #+#             */
/*   Updated: 2025/04/11 18:10:36 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_pointer_pf(void *ptr)
{
	int		i;
	char	*hex;

	if (!ptr)
	{
		return (write (1, "(nil)", 5));
	}
	hex = convert_base((unsigned long)ptr, HEX_BASE_LOWER);
	if (!hex)
		return (0);
	write (1, "0x", 2);
	i = 0;
	while (hex[i] != '\0')
	{
		write (1, &hex[i], 1);
		i++;
	}
	free (hex);
	return (i + 2);
}
