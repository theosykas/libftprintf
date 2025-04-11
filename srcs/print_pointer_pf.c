/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:51:37 by theo              #+#    #+#             */
/*   Updated: 2025/04/11 17:03:41 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*char	*convert_base(unsigned int n, const char *base)
{
	char			*res;
	int				len_base;
	int				len;
	unsigned int	tmp;

	len_base = 0;
	while (base[len_base])
		len_base++;
	len = 1;
	tmp = n;
	while (tmp / len_base != 0)
	{
		tmp /= len_base;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (len > 0)
	{
		res[--len] = base[n % len_base];
		n /= len_base;
	}
	return (res);
}*/

int	print_pointer_pf(void *ptr)
{
	int		i;
	char	*hex;

	if (ptr == 0)
	{
		write (1, "(nil)", 5);
		return (5);
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
