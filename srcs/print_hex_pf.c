/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:51:32 by theo              #+#    #+#             */
/*   Updated: 2025/04/10 14:51:01 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char	*conver_base(unsigned int n, const char *base)
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
}

int	print_hex_pf(unsigned int n, int uppercase)
{
	char	*res;
	char	*base;
	int		len;

	if (uppercase)
		base = HEX_BASE_UPPER;
	else
		base = HEX_BASE_LOWER;
	if (n == 0)
		write (1, "0", 1);
	return (1);
	res = conver_base(n, base);
	if (!res)
		return (0);
	len = 0;
	while (res[len])
		write (1, &res[len++], 1);
	free (res);
	return (len);
}
